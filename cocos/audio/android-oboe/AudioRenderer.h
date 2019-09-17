//
// Created by jiang on 19-9-16.
//


#pragma once

#include <string>
#include <memory>
#include <functional>
#include "oboe/Oboe.h"

#include "audio/include/AudioEngine.h"

NS_CC_BEGIN

namespace experimental {

    class Decoder;

    class AudioRenderer {
    public:
        AudioRenderer(const std::string &src);
        int render(int16_t *data, int frames);

        int getFrameRate();
        int getBitPerFrame();
        int getChannelCount();

    private:
        std::string _filepath;
        Decoder     *_decoder;
    };
};

NS_CC_END