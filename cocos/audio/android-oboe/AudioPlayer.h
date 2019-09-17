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
    class AudioRenderer;

    class AudioPlayer {
    public:
        AudioPlayer(const std::string &, float, bool);

        virtual ~AudioPlayer();

        void play();

        void stop();

        void pause();

        void resume();

        void setLoop(bool);

        //[0.0f, 1.0f]
        void setVolume(float);

        bool getLoop();

        float getVolume();

        const std::string &getPath();

        float getDuration();

        bool setCurrentTime(float);

        float getCurrentTime();

        void setFinishCallback(const std::function<void(int, const std::string &)> cb);

        AudioEngine::AudioState getState();

    private:

        oboe::AudioStreamBuilder _builder;
        std::shared_ptr<AudioRenderer> _renderer;
        oboe::AudioStream *_stream = nullptr;
        float _volume = 1.0f;
        std::shared_ptr<oboe::AudioStreamCallback> _callback;
    };

};

NS_CC_END

