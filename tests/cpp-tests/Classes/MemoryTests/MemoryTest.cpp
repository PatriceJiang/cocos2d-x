/****************************************************************************
 Copyright (c) 2019 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos.com
 
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

#include "MemoryTest.h"
#include <unistd.h>

USING_NS_CC;

template <typename T> std::string tostr(const T& t) { std::ostringstream os; os<<t; return os.str(); }

//static int64_t get_memory_used()
//{
//    uv_rusage_t usage;
//    memset(&usage, 0, sizeof(usage));
//    uv_getrusage(&usage);
//    return usage.ru_maxrss;
//}

static int64_t get_memory_used()
{
    FILE *fp = fopen("/proc/self/statm", "rt");
    if(!fp) {
        return -1;
    }
    int size = 0;
    int resident = 0;
    int shared = 0;
    fscanf(fp, "%d %d %d", &size, &resident, &shared);
   // return resident * sysconf(_SC_PAGE_SIZE);
   return size * sysconf(_SC_PAGE_SIZE);;
}

class mem_item {
public:
    void begin() { _before = get_memory_used();}
    int64_t end() {_after = get_memory_used(); return _after - _before;}
    int64_t get() {
        CCASSERT(_after > 0 && _before > 0 , "should invoke both begin() & end()");
        return _after - _before;
    }
private:
    int64_t _before = 0;
    int64_t _after = 0;
};

static struct {
    mem_item alloc_sprites;
    mem_item alloc_textures;
    mem_item alloc_3d;
} memory_info;

MemoryUsageTests::MemoryUsageTests()
{
    ADD_TEST_CASE(MemoryUsageTest);
}

//------------------------------------------------------------------
//
// MemoryUsageTest
//
//------------------------------------------------------------------
MemoryUsageTest::MemoryUsageTest()
{
    auto s = Director::getInstance()->getWinSize();
    memset(&memory_info, 0, sizeof(memory_info));
    const int SPRITE_COUNT = 1024 * 10;
    std::vector<Sprite*> sprites;
    sprites.reserve(SPRITE_COUNT);
    memory_info.alloc_sprites.begin();
    for(int i=0; i< SPRITE_COUNT; i++) {
        auto *s = Sprite::create("Images/test_blend.png");
        if(s) {
            sprites.push_back(s);
        }
    }
    memory_info.alloc_sprites.end();

    std::stringstream ss;
    ss << "Create " << sprites.size() << " sprites, " << memory_info.alloc_sprites.get() * 1.0 / sprites.size() << " bytes per sprite";

    _labelMemOfSprites = Label::createWithTTF(TTFConfig("fonts/Courier New.ttf"), ss.str());
    _labelMemOfSprites->setPosition(s.width/2, s.height / 2);
    addChild(_labelMemOfSprites);
}


std::string MemoryUsageTest::title() const
{
    return "Memory usage Test";
}

std::string MemoryUsageTest::subtitle() const
{
    return "This tests memory usage";
}
