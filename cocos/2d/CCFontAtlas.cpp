/****************************************************************************
 Copyright (c) 2013      Zynga Inc.
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "2d/CCFontAtlas.h"
#if CC_TARGET_PLATFORM != CC_PLATFORM_WIN32 && CC_TARGET_PLATFORM != CC_PLATFORM_WINRT && CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
#include <iconv.h>
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.h"
#endif
#include "2d/CCFontFreeType.h"
#include "base/ccUTF8.h"
#include "base/CCDirector.h"
#include "base/CCEventListenerCustom.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventType.h"

NS_CC_BEGIN

const int FontAtlas::CacheTextureWidth = 512;
const int FontAtlas::CacheTextureHeight = 512;
const char* FontAtlas::CMD_PURGE_FONTATLAS = "__cc_PURGE_FONTATLAS";
const char* FontAtlas::CMD_RESET_FONTATLAS = "__cc_RESET_FONTATLAS";


void LetterDefinitions::set(char32_t character, const FontLetterDefinition &value)
{
    normalDict[character] = value;
}

void LetterDefinitions::setTTF(char32_t character, const _ttfConfig &config, const FontLetterDefinition &value)
{
    ttfDict[config.getCharHash(character)] = value;
}

FontLetterDefinition* LetterDefinitions::get(char32_t key)
{
    if (normalDict.find(key) == normalDict.end()) {
        return nullptr;
    }
    else {
        return &normalDict[key];
    }
        
}

FontLetterDefinition* LetterDefinitions::getTTF(char32_t character, const _ttfConfig &config)
{
    auto key = config.getCharHash(character);
    if (ttfDict.find(key) == ttfDict.end()) {
        return nullptr;
    }
    else {
        return &ttfDict[key];
    }
}


FontLetterDefinition* LetterDefinitions::getForLabel(char32_t character, Label *label)
{
    if (label->_currentLabelType == Label::LabelType::TTF) 
    {
        return getTTF(character, label->getTTFConfig());
    }
    else
    {
        return get(character);
    }
}

FontAtlas::FontAtlas(Font &theFont) 
: _font(&theFont)
{
    _font->retain();

    auto *fontFreeType = dynamic_cast<FontFreeType*>(_font);
    if (fontFreeType)
    {
        _isTTF = true;
        _currentLineHeight = _font->getFontMaxHeight();
        _fontAscender = fontFreeType->getFontAscender();
        _currentPage = 0;
        _currentPageOrigX = 0;
        _currentPageOrigY = 0;
        _letterEdgeExtend = 2;
        _letterPadding = 0;
        _hasOutline = fontFreeType->getOutlineSize() > 0;

        if (fontFreeType->isDistanceFieldEnabled())
        {
            _letterPadding += 2 * FontFreeType::DistanceMapSpread;    
        }

#if CC_ENABLE_CACHE_TEXTURE_DATA
        auto eventDispatcher = Director::getInstance()->getEventDispatcher();

        _rendererRecreatedListener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, CC_CALLBACK_1(FontAtlas::listenRendererRecreated, this));
        eventDispatcher->addEventListenerWithFixedPriority(_rendererRecreatedListener, 1);
#endif
    }
}

void FontAtlas::reinit()
{
    if (_currentPageData)
    {
        delete []_currentPageData;
        _currentPageData = nullptr;
    }
    
    auto texture = new (std::nothrow) Texture2D;
    
    _currentPageDataSize = CacheTextureWidth * CacheTextureHeight;
    
    if(_hasOutline)
    {
        _currentPageDataSize *= 2;
    }
    
    _currentPageData = new (std::nothrow) unsigned char[_currentPageDataSize];
    memset(_currentPageData, 0, _currentPageDataSize);
    
    auto  pixelFormat = _hasOutline ? Texture2D::PixelFormat::AI88 : Texture2D::PixelFormat::A8;
    texture->initWithData(_currentPageData, _currentPageDataSize,
                          pixelFormat, CacheTextureWidth, CacheTextureHeight, Size(CacheTextureWidth,CacheTextureHeight) );
    
    addTexture(texture,0);
    texture->release();
}

FontAtlas::~FontAtlas()
{
#if CC_ENABLE_CACHE_TEXTURE_DATA
    if (_fontFreeType && _rendererRecreatedListener)
    {
        auto eventDispatcher = Director::getInstance()->getEventDispatcher();
        eventDispatcher->removeEventListener(_rendererRecreatedListener);
        _rendererRecreatedListener = nullptr;
    }
#endif

    _font->release();
    releaseTextures();

    delete []_currentPageData;

#if CC_TARGET_PLATFORM != CC_PLATFORM_WIN32 && CC_TARGET_PLATFORM != CC_PLATFORM_WINRT && CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
    if (_iconv)
    {
        iconv_close(_iconv);
        _iconv = nullptr;
    }
#endif
}

void FontAtlas::reset()
{
    releaseTextures();
    
    _currLineHeight = 0;
    _currentPage = 0;
    _currentPageOrigX = 0;
    _currentPageOrigY = 0;
    _letterDefinitions.clear();
    
    reinit();
}

void FontAtlas::releaseTextures()
{
    for( auto &item: _atlasTextures)
    {
        item.second->release();
    }
    _atlasTextures.clear();
}

void FontAtlas::purgeTexturesAtlas()
{
    if (!_fontFreeTypeMap.empty())
    {
        reset();
        auto eventDispatcher = Director::getInstance()->getEventDispatcher();
        eventDispatcher->dispatchCustomEvent(CMD_PURGE_FONTATLAS,this);
        eventDispatcher->dispatchCustomEvent(CMD_RESET_FONTATLAS,this);
    }
}

void FontAtlas::listenRendererRecreated(EventCustom * /*event*/)
{
    purgeTexturesAtlas();
}

void FontAtlas::addLetterDefinition(char32_t utf32Char, const FontLetterDefinition &letterDefinition)
{
    CCASSERT(!_isTTF, "addLetterDefinition should not be used in FreeTypeFont");
    _letterDefinitions.set(utf32Char, letterDefinition);
}

void FontAtlas::scaleFontLetterDefinition(float scaleFactor)
{
    for (auto&& fontDefinition : _letterDefinitions.getTTFDict()) {
        auto& letterDefinition = fontDefinition.second;
        letterDefinition.width *= scaleFactor;
        letterDefinition.height *= scaleFactor;
        letterDefinition.offsetX *= scaleFactor;
        letterDefinition.offsetY *= scaleFactor;
        letterDefinition.xAdvance *= scaleFactor;
    }

    for (auto&& fontDefinition : _letterDefinitions.getNormalDict()) {
        auto& letterDefinition = fontDefinition.second;
        letterDefinition.width *= scaleFactor;
        letterDefinition.height *= scaleFactor;
        letterDefinition.offsetX *= scaleFactor;
        letterDefinition.offsetY *= scaleFactor;
        letterDefinition.xAdvance *= scaleFactor;
    }
}

bool FontAtlas::getLetterDefinitionForChar(const _ttfConfig *config, char32_t utf32Char, FontLetterDefinition &letterDefinition)
{
    auto *def = config == nullptr ? _letterDefinitions.get(utf32Char) : _letterDefinitions.getTTF(utf32Char, *config);
    if (def != nullptr)
    {
        letterDefinition = *def;
        return letterDefinition.validDefinition;
    }
    else
    {
        return false;
    }
}

void FontAtlas::conversionU32TOGB2312(FontFreeType *fontFreeType, const std::u32string& u32Text, std::unordered_map<unsigned int, unsigned int>& charCodeMap)
{
    size_t strLen = u32Text.length();
    auto gb2312StrSize = strLen * 2;
    auto gb2312Text = new (std::nothrow) char[gb2312StrSize];
    memset(gb2312Text, 0, gb2312StrSize);

    switch (fontFreeType->getEncoding())
    {
    case FT_ENCODING_GB2312:
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
        std::u16string u16Text;
        cocos2d::StringUtils::UTF32ToUTF16(u32Text, u16Text);
        WideCharToMultiByte(936, NULL, (LPCWCH)u16Text.c_str(), strLen, (LPSTR)gb2312Text, gb2312StrSize, NULL, NULL);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        conversionEncodingJNI((char*)u32Text.c_str(), gb2312StrSize, "UTF-32LE", gb2312Text, "GB2312");
#else
        if (_iconv == nullptr)
        {
            _iconv = iconv_open("GBK//TRANSLIT", "UTF-32LE");
        }

        if (_iconv == (iconv_t)-1)
        {
            CCLOG("conversion from utf32 to gb2312 not available");
        }
        else
        {
            char* pin = (char*)u32Text.c_str();
            char* pout = gb2312Text;
            size_t inLen = strLen * 2;
            size_t outLen = gb2312StrSize;

            iconv(_iconv, (char**)&pin, &inLen, &pout, &outLen);
        }
#endif
    }
    break;
    default:
        CCLOG("Unsupported encoding:%d", fontFreeType->getEncoding());
        break;
    }

    unsigned short gb2312Code = 0;
    unsigned char* dst = (unsigned char*)&gb2312Code;
    char32_t u32Code;
    for (size_t index = 0, gbIndex = 0; index < strLen; ++index)
    {
        u32Code = u32Text[index];
        if (u32Code < 256)
        {
            charCodeMap[u32Code] = u32Code;
            gbIndex += 1;
        }
        else
        {
            dst[0] = gb2312Text[gbIndex + 1];
            dst[1] = gb2312Text[gbIndex];
            charCodeMap[u32Code] = gb2312Code;

            gbIndex += 2;
        }
    }

    delete[] gb2312Text;
}

void FontAtlas::findNewCharacters(const _ttfConfig &config, FontFreeType *fontFreeType, const std::u32string& u32Text, std::unordered_map<unsigned int, unsigned int>& charCodeMap)
{
    std::u32string newChars;
    FT_Encoding charEncoding = fontFreeType->getEncoding();

    //find new characters
    if (_letterDefinitions.empty())
    {
        // fixed #16169: new android project crash in android 5.0.2 device (Nexus 7) when use 3.12.
        // While using clang compiler with gnustl_static on android, the copy assignment operator of `std::u32string`
        // will affect the memory validity, it means after `newChars` is destroyed, the memory of `u32Text` holds
        // will be a dead region. `u32text` represents the variable in `Label::_utf32Text`, when somewhere
        // allocates memory by `malloc, realloc, new, new[]`, the generated memory address may be the same
        // as `Label::_utf32Text` holds. If doing a `memset` or other memory operations, the orignal `Label::_utf32Text`
        // will be in an unknown state. Meanwhile, a bunch lots of logic which depends on `Label::_utf32Text`
        // will be broken.
        
        // newChars = u32Text;
        
        // Using `append` method is a workaround for this issue. So please be carefuly while using the assignment operator
        // of `std::u32string`.
        newChars.append(u32Text);
    }
    else
    {
        auto length = u32Text.length();
        newChars.reserve(length);
        for (size_t i = 0; i < length; ++i)
        {
            auto *def= _letterDefinitions.getTTF( u32Text[i], config);
            if (def == nullptr)
            {
                newChars.push_back(u32Text[i]);
            }
        }
    }

    if (!newChars.empty())
    {
        switch (charEncoding)
        {
        case FT_ENCODING_UNICODE:
        {
            for (auto u32Code : newChars)
            {
                charCodeMap[u32Code] = u32Code;
            }
            break;
        }
        case FT_ENCODING_GB2312:
        {
            conversionU32TOGB2312(fontFreeType, newChars, charCodeMap);
            break;
        }
        default:
            CCLOG("FontAtlas::findNewCharacters: Unsupported encoding:%d", charEncoding);
            break;
        }
    }
}

bool FontAtlas::prepareLetterDefinitions(const _ttfConfig &config, const std::u32string& utf32Text)
{
    if (_fontFreeTypeMap.find(config.getFontHash()) == _fontFreeTypeMap.end())
    {
        return false;
    }

    auto *fontFreeType = _fontFreeTypeMap[config.getFontHash()];

 
    if (!_currentPageData)
        reinit();     
 
    std::unordered_map<unsigned int, unsigned int> codeMapOfNewChar;
    findNewCharacters(config, fontFreeType, utf32Text, codeMapOfNewChar);
    if (codeMapOfNewChar.empty())
    {
        return false;
    }

    int adjustForDistanceMap = _letterPadding / 2;
    int adjustForExtend = _letterEdgeExtend / 2;
    long bitmapWidth;
    long bitmapHeight;
    int glyphHeight;
    Rect tempRect;
    FontLetterDefinition tempDef;

    auto scaleFactor = CC_CONTENT_SCALE_FACTOR();
    auto  pixelFormat = fontFreeType->getOutlineSize() > 0 ? Texture2D::PixelFormat::AI88 : Texture2D::PixelFormat::A8;

    float startY = _currentPageOrigY;

    for (auto&& it : codeMapOfNewChar)
    {
        auto bitmap = fontFreeType->getGlyphBitmap(it.second, bitmapWidth, bitmapHeight, tempRect, tempDef.xAdvance);
        if (bitmap && bitmapWidth > 0 && bitmapHeight > 0)
        {
            tempDef.validDefinition = true;
            tempDef.width = tempRect.size.width + _letterPadding + _letterEdgeExtend;
            tempDef.height = tempRect.size.height + _letterPadding + _letterEdgeExtend;
            tempDef.offsetX = tempRect.origin.x - adjustForDistanceMap - adjustForExtend;
            tempDef.offsetY = _fontAscender + tempRect.origin.y - adjustForDistanceMap - adjustForExtend;

            if (_currentPageOrigX + tempDef.width > CacheTextureWidth)
            {
                _currentPageOrigY += _currLineHeight;
                _currLineHeight = 0;
                _currentPageOrigX = 0;
                if (_currentPageOrigY + _currentLineHeight + _letterPadding + _letterEdgeExtend >= CacheTextureHeight)
                {
                    unsigned char *data = nullptr;
                    if (pixelFormat == Texture2D::PixelFormat::AI88)
                    {
                        data = _currentPageData + CacheTextureWidth * (int)startY * 2;
                    }
                    else
                    {
                        data = _currentPageData + CacheTextureWidth * (int)startY;
                    }
                    _atlasTextures[_currentPage]->updateWithData(data, 0, startY,
                        CacheTextureWidth, CacheTextureHeight - startY);

                    startY = 0.0f;

                    _currentPageOrigY = 0;
                    memset(_currentPageData, 0, _currentPageDataSize);
                    _currentPage++;
                    auto tex = new (std::nothrow) Texture2D;
                    if (_antialiasEnabled)
                    {
                        tex->setAntiAliasTexParameters();
                    }
                    else
                    {
                        tex->setAliasTexParameters();
                    }
                    tex->initWithData(_currentPageData, _currentPageDataSize,
                        pixelFormat, CacheTextureWidth, CacheTextureHeight, Size(CacheTextureWidth, CacheTextureHeight));
                    addTexture(tex, _currentPage);
                    tex->release();
                }
            }
            glyphHeight = static_cast<int>(bitmapHeight) + _letterPadding + _letterEdgeExtend;
            if (glyphHeight > _currLineHeight)
            {
                _currLineHeight = glyphHeight;
            }
            fontFreeType->renderCharAt(_currentPageData, _currentPageOrigX + adjustForExtend, _currentPageOrigY + adjustForExtend, bitmap, bitmapWidth, bitmapHeight);

            tempDef.U = _currentPageOrigX;
            tempDef.V = _currentPageOrigY;
            tempDef.textureID = _currentPage;
            _currentPageOrigX += tempDef.width + 1;
            // take from pixels to points
            tempDef.width = tempDef.width / scaleFactor;
            tempDef.height = tempDef.height / scaleFactor;
            tempDef.U = tempDef.U / scaleFactor;
            tempDef.V = tempDef.V / scaleFactor;
        }
        else{
            delete[] bitmap;
            if (tempDef.xAdvance)
                tempDef.validDefinition = true;
            else
                tempDef.validDefinition = false;

            tempDef.width = 0;
            tempDef.height = 0;
            tempDef.U = 0;
            tempDef.V = 0;
            tempDef.offsetX = 0;
            tempDef.offsetY = 0;
            tempDef.textureID = 0;
            _currentPageOrigX += 1;
        }

        _letterDefinitions.setTTF(it.first, config, tempDef);
    }

    unsigned char *data = nullptr;
    if (pixelFormat == Texture2D::PixelFormat::AI88)
    {
        data = _currentPageData + CacheTextureWidth * (int)startY * 2;
    }
    else
    {
        data = _currentPageData + CacheTextureWidth * (int)startY;
    }
    _atlasTextures[_currentPage]->updateWithData(data, 0, startY, CacheTextureWidth, _currentPageOrigY - startY + _currLineHeight);

    return true;
}

void FontAtlas::addTexture(Texture2D *texture, int slot)
{
    texture->retain();
    _atlasTextures[slot] = texture;
}

Texture2D* FontAtlas::getTexture(int slot)
{
    return _atlasTextures[slot];
}

void FontAtlas::setLineHeight(float newHeight)
{
    _currentLineHeight = newHeight;
}

float FontAtlas::getLineHeightForLabel(Label *label) const {

    if (label->_currentLabelType != Label::LabelType::TTF) {
        return _currentLineHeight;
    }
    auto &cfg = label->getTTFConfig();
    if (_fontFreeTypeMap.find(cfg.getFontHash()) == _fontFreeTypeMap.end()) {
        return _currentLineHeight;
    }
    auto *fontFreeType = _fontFreeTypeMap.at(cfg.getFontHash());

    return fontFreeType->getFontMaxHeight()  + (cfg.outlineSize > 0 ? 2 * cfg.outlineSize : 0);
}

std::string FontAtlas::getFontName() const
{
    return ""; //may contain multiple fonts
}

void FontAtlas::setAliasTexParameters()
{
    if (_antialiasEnabled)
    {
        _antialiasEnabled = false;
        for (const auto & tex : _atlasTextures)
        {
            tex.second->setAliasTexParameters();
        }
    }
}

void FontAtlas::setAntiAliasTexParameters()
{
    if (! _antialiasEnabled)
    {
        _antialiasEnabled = true;
        for (const auto & tex : _atlasTextures)
        {
            tex.second->setAntiAliasTexParameters();
        }
    }
}

void FontAtlas::registerFont(const _ttfConfig &config, FontFreeType *font)
{
    if (font && _fontFreeTypeMap.find(config.getFontHash()) == _fontFreeTypeMap.end()) {

        CCASSERT(_hasOutline == (config.outlineSize > 0), "outline should not be alter!");

        _fontFreeTypeMap.emplace(config.getFontHash(), font);
        font->retain();
        /*auto newLineHeight = _font->getFontMaxHeight() + (config.outlineSize > 0 ? 2 * config.outlineSize : 0);
        if(newLineHeight > _currentLineHeight) {
            _currentLineHeight = newLineHeight;
        }*/
        /*auto newFontAscender = font->getFontAscender();
        if (newFontAscender > _fontAscender) {
            _fontAscender = newFontAscender;
        }*/
    }
}

bool FontAtlas::hasFont(const _ttfConfig &config) {
    return _fontFreeTypeMap.find(config.getFontHash()) != _fontFreeTypeMap.end();
}

NS_CC_END
