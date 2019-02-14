/****************************************************************************
Copyright (c) 2019 Xiamen Yaji Software Co., Ltd.

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

#include "TextureCubeGL.h"
#include "renderer/CCTextureCube.h"
#include "renderer/backend/Texture.h"
#include "renderer/backend/opengl/TextureGL.h"
#include "base/ccMacros.h"
#include "platform/CCImage.h"
#include "platform/CCFileUtils.h"


NS_CC_BEGIN


static unsigned char* getImageData(Image* img, Texture2D::PixelFormat&  ePixFmt)
{
    unsigned char*    pTmpData = img->getData();
    unsigned int*     inPixel32 = nullptr;
    unsigned char*    inPixel8 = nullptr;
    unsigned short*   outPixel16 = nullptr;
    bool              bHasAlpha = img->hasAlpha();
    size_t            uBPP = img->getBitPerPixel();

    int               nWidth = img->getWidth();
    int               nHeight = img->getHeight();

    // compute pixel format
    if (bHasAlpha)
    {
        ePixFmt = Texture2D::PixelFormat::DEFAULT;
    }
    else
    {
        if (uBPP >= 8)
        {
            ePixFmt = Texture2D::PixelFormat::RGB888;
        }
        else
        {
            ePixFmt = Texture2D::PixelFormat::RGB565;
        }
    }

    // Repack the pixel data into the right format
    unsigned int uLen = nWidth * nHeight;

    if (ePixFmt == Texture2D::PixelFormat::RGB565)
    {
        if (bHasAlpha)
        {
            // Convert "RRRRRRRRRGGGGGGGGBBBBBBBBAAAAAAAA" to "RRRRRGGGGGGBBBBB"
            inPixel32 = (unsigned int*)img->getData();
            pTmpData = new (std::nothrow) unsigned char[nWidth * nHeight * 2];
            outPixel16 = (unsigned short*)pTmpData;

            for (unsigned int i = 0; i < uLen; ++i, ++inPixel32)
            {
                *outPixel16++ =
                    ((((*inPixel32 >> 0) & 0xFF) >> 3) << 11) |  // R
                    ((((*inPixel32 >> 8) & 0xFF) >> 2) << 5) |  // G
                    ((((*inPixel32 >> 16) & 0xFF) >> 3) << 0);    // B
            }
        }
        else
        {
            // Convert "RRRRRRRRGGGGGGGGBBBBBBBB" to "RRRRRGGGGGGBBBBB"
            pTmpData = new (std::nothrow) unsigned char[nWidth * nHeight * 2];
            outPixel16 = (unsigned short*)pTmpData;
            inPixel8 = (unsigned char*)img->getData();

            for (unsigned int i = 0; i < uLen; ++i)
            {
                unsigned char R = *inPixel8++;
                unsigned char G = *inPixel8++;
                unsigned char B = *inPixel8++;

                *outPixel16++ =
                    ((R >> 3) << 11) |  // R
                    ((G >> 2) << 5) |  // G
                    ((B >> 3) << 0);    // B
            }
        }
    }

    if (bHasAlpha && ePixFmt == Texture2D::PixelFormat::RGB888)
    {
        // Convert "RRRRRRRRRGGGGGGGGBBBBBBBBAAAAAAAA" to "RRRRRRRRGGGGGGGGBBBBBBBB"
        inPixel32 = (unsigned int*)img->getData();

        pTmpData = new (std::nothrow) unsigned char[nWidth * nHeight * 3];
        unsigned char* outPixel8 = pTmpData;

        for (unsigned int i = 0; i < uLen; ++i, ++inPixel32)
        {
            *outPixel8++ = (*inPixel32 >> 0) & 0xFF; // R
            *outPixel8++ = (*inPixel32 >> 8) & 0xFF; // G
            *outPixel8++ = (*inPixel32 >> 16) & 0xFF; // B
        }
    }

    return pTmpData;
}

static Image* createImage(const std::string& path)
{
    // Split up directory and filename
    // MUTEX:
    // Needed since addImageAsync calls this method from a different thread

    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(path);
    if (fullpath.size() == 0)
    {
        return nullptr;
    }

    // all images are handled by UIImage except PVR extension that is handled by our own handler
    Image* image = nullptr;
    do
    {
        image = new (std::nothrow) Image();
        CC_BREAK_IF(nullptr == image);

        bool bRet = image->initWithImageFile(fullpath);
        CC_BREAK_IF(!bRet);
    } while (0);

    return image;
}


TextureCube* TextureCube::create(const std::string& positive_x, const std::string& negative_x,
    const std::string& positive_y, const std::string& negative_y,
    const std::string& positive_z, const std::string& negative_z)
{
    auto ret = new (std::nothrow) backend::TextureCubeGL();
    if (ret && ret->init(positive_x, negative_x, positive_y, negative_y, positive_z, negative_z))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

NS_CC_END

CC_BACKEND_BEGIN

bool TextureCubeGL::init(const std::string& positive_x, const std::string& negative_x,
                       const std::string& positive_y, const std::string& negative_y,
                       const std::string& positive_z, const std::string& negative_z)
{
    _imgPath[0] = positive_x;
    _imgPath[1] = negative_x;
    _imgPath[2] = positive_y;
    _imgPath[3] = negative_y;
    _imgPath[4] = positive_z;
    _imgPath[5] = negative_z;
    CC_SAFE_RELEASE_NULL(_texture);

    auto descriptor = backend::TextureDescriptor();
    descriptor.textureType = TextureType::TEXTURE_CUBE;
    descriptor.textureUsage = TextureUsage::READ;
    descriptor.width = 4;
    descriptor.height = 4;
    _texture = new TextureCubeMapGL(descriptor);

    TextureCubeMapGL *cube = static_cast<TextureCubeMapGL*>(_texture);

    std::vector<Image*> images(6);

    images[0] = createImage(positive_x);
    images[1] = createImage(negative_x);
    images[2] = createImage(positive_y);
    images[3] = createImage(negative_y);
    images[4] = createImage(positive_z);
    images[5] = createImage(negative_z);
    
    for (int i = 0; i < 6; i++)
    {
        Image* img = images[i];

        Texture2D::PixelFormat  ePixelFmt;
        unsigned char*          pData = getImageData(img, ePixelFmt);
        cube->updateImageData(i, ePixelFmt, img->getWidth(), img->getHeight(), pData);
        if (pData != img->getData())
            delete[] pData;
    }

    TexParams params;
    params.minFilter = GL_LINEAR;
    params.magFilter = GL_LINEAR;
    params.wrapS = GL_CLAMP_TO_EDGE;
    params.wrapT = GL_CLAMP_TO_EDGE;
    setTexParameters(params);

    return true;
}

void TextureCubeGL::setTexParameters(const TexParams& texParams)
{
    TextureCubeMapGL *cube = static_cast<TextureCubeMapGL*>(_texture);
    cube->setTexParams(texParams);
}

CC_BACKEND_END
