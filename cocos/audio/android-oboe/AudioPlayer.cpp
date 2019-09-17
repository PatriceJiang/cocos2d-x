//
// Created by jiang on 19-9-16.
//

#include "AudioPlayer.h"
#include "AudioRenderer.h"

NS_CC_BEGIN

    namespace experimental {

        class MyCallback : public oboe::AudioStreamCallback {
        public:

            MyCallback(AudioRenderer *renderer, AudioPlayer *player) :
                    _renderer(renderer),
                    _player(player) {}

            oboe::DataCallbackResult
            onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames) {
                int16_t *output = static_cast<int16_t *>(audioData);
                int frames = _renderer->render(output, numFrames);
                float v = _player->getVolume();
                if(v < 1.0f) {
                    for(int i=0;i<frames; i++) {
                        output[2 * i] = (int16_t) v * output[2 * i];
                        output[2 * i + 1] = (int16_t) v * output[2 * i + 1];
                    }
                }
                return frames > 0 ? oboe::DataCallbackResult::Continue : oboe::DataCallbackResult ::Stop;
            }

        private:
            AudioRenderer *_renderer = nullptr;
            AudioPlayer *_player = nullptr;
        };

        AudioPlayer::AudioPlayer(const std::string &path, float volume, bool loop) {

            _renderer = std::make_shared<AudioRenderer>(path);

            _callback = std::make_shared<MyCallback>(_renderer, this);

            _builder.setDirection(oboe::Direction::Output);
            _builder.setPerformanceMode(oboe::PerformanceMode::LowLatency);
            _builder.setSharingMode(oboe::SharingMode::Exclusive);
            _builder.setFormat(oboe::AudioFormat::I16);
            _builder.setChannelCount(oboe::ChannelCount::Mono);
            _builder.setCallback(_callback.get());
            _builder.setUsage(oboe::Usage::Game);


            _builder.openStream(&_stream);
        }

        AudioPlayer::~AudioPlayer() {
            if (_stream) {
                _stream->close();
            }
        }

        void AudioPlayer::play() {
            if (_stream) {
                _stream->requestStart();
            }
        }

        void AudioPlayer::stop() {
            if (_stream) {
                _stream->requestStop();
            }
        }

        void AudioPlayer::pause() {
            if (_stream) {
                _stream->requestPause();
            }
        }

        void AudioPlayer::resume() {
            if (_stream) {
                _stream->requestStart();
            }
        }

    };

NS_CC_END