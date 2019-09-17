/****************************************************************************
 Copyright (c) 2014-2016 Chukong Technologies Inc.
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

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "platform/CCPlatformConfig.h"

#include "audio/include/AudioEngine.h"
//#include "audio/android-oboe/AudioEngine-android.h"
#include "audio/android-oboe/AudioPlayer.h"

#include <condition_variable>
#include <queue>
#include "platform/CCFileUtils.h"
#include "base/ccUtils.h"


#define TIME_DELAY_PRECISION 0.0001
#define MAX_AUDIOINSTANCES 24

#ifdef ERROR
#undef ERROR
#endif // ERROR

using namespace cocos2d;
using namespace cocos2d::experimental;

const int AudioEngine::INVALID_AUDIO_ID = -1;
const float AudioEngine::TIME_UNKNOWN = -1.0f;

//audio file path,audio IDs
std::unordered_map<std::string,std::list<int>> AudioEngine::_audioPathIDMap;
//profileName,ProfileHelper
std::unordered_map<std::string, AudioEngine::ProfileHelper> AudioEngine::_audioPathProfileHelperMap;
unsigned int AudioEngine::_maxInstances = MAX_AUDIOINSTANCES;
AudioEngine::ProfileHelper* AudioEngine::_defaultProfileHelper = nullptr;
std::unordered_map<int, std::shared_ptr<AudioPlayer>> AudioEngine::_audioPlayers;
//AudioEngineImpl* AudioEngine::_audioEngineImpl = nullptr;

bool AudioEngine::_isEnabled = true;

static int _playerInnerIndexInt = 10000;

void AudioEngine::end()
{

    delete _defaultProfileHelper;
    _defaultProfileHelper = nullptr;
}

bool AudioEngine::lazyInit()
{
    return true;
}

int AudioEngine::play2d(const std::string& filePath, bool loop, float volume, const AudioProfile *profile)
{
    int ret = AudioEngine::INVALID_AUDIO_ID;

    do {
        if (!isEnabled())
        {
            break;
        }

        if ( !lazyInit() ){
            break;
        }

        if ( !FileUtils::getInstance()->isFileExist(filePath)){
            break;
        }

        auto profileHelper = _defaultProfileHelper;
        if (profile && profile != &profileHelper->profile){
            CC_ASSERT(!profile->name.empty());
            profileHelper = &_audioPathProfileHelperMap[profile->name];
            profileHelper->profile = *profile;
        }

        if (_audioPlayers.size() >= _maxInstances) {
            log("Fail to play %s cause by limited max instance of AudioEngine",filePath.c_str());
            break;
        }
        if (profileHelper)
        {
            if(profileHelper->profile.maxInstances != 0 && profileHelper->audioIDs.size() >= profileHelper->profile.maxInstances){
                log("Fail to play %s cause by limited max instance of AudioProfile",filePath.c_str());
                break;
            }
            if (profileHelper->profile.minDelay > TIME_DELAY_PRECISION) {
                auto currTime = utils::gettime();
                if (profileHelper->lastPlayTime > TIME_DELAY_PRECISION && currTime - profileHelper->lastPlayTime <= profileHelper->profile.minDelay) {
                    log("Fail to play %s cause by limited minimum delay",filePath.c_str());
                    break;
                }
            }
        }

        if (volume < 0.0f) {
            volume = 0.0f;
        }
        else if (volume > 1.0f){
            volume = 1.0f;
        }

        std::shared_ptr<AudioPlayer> player = std::make_shared<AudioPlayer>(filePath, volume, loop);

        auto ret =_playerInnerIndexInt++;
        _audioPlayers[ret] = player;

        //ret = _audioEngineImpl->play2d(filePath, loop, volume);

        player->play();

        if (ret != INVALID_AUDIO_ID)
        {
            _audioPathIDMap[filePath].push_back(ret);
            auto it = _audioPathIDMap.find(filePath);

            if (profileHelper) {
                profileHelper->lastPlayTime = utils::gettime();
                profileHelper->audioIDs.push_back(ret);
            }
        }
    } while (0);

    return ret;
}

void AudioEngine::setLoop(int audioID, bool loop)
{
    auto it = _audioPlayers.find(audioID);
    if (it != _audioPlayers.end() && it->second->getLoop() != loop){
        it->second->setLoop(loop);
    }
}

void AudioEngine::setVolume(int audioID, float volume)
{
    auto it = _audioPlayers.find(audioID);
    if (it != _audioPlayers.end()){
        it->second->setVolume(volume);
    }
}

void AudioEngine::pause(int audioID)
{
    auto it = _audioPlayers.find(audioID);
    if (it != _audioPlayers.end()){
        it->second->pause();
    }
}

void AudioEngine::pauseAll()
{
    auto itEnd = _audioPlayers.end();
    for (auto it = _audioPlayers.begin(); it != itEnd; ++it)
    {
        it->second->pause();
    }
}

void AudioEngine::resume(int audioID)
{
    auto it = _audioPlayers.find(audioID);
    if (it != _audioPlayers.end()){
        it->second->resume();
    }
}

void AudioEngine::resumeAll()
{
    auto itEnd = _audioPlayers.end();
    for (auto it = _audioPlayers.begin(); it != itEnd; ++it)
    {
        it->second->resume();
    }
}

void AudioEngine::stop(int audioID)
{
    auto it = _audioPlayers.end();
    if (it != _audioPlayers.end())
    {
        it->second->stop();
        remove(audioID);
    }

}

void AudioEngine::remove(int audioID)
{
    _audioPathIDMap[_audioPlayers[audioID]->getPath()].remove(audioID);
    _audioPlayers.erase(audioID);
}

void AudioEngine::stopAll()
{
    auto itEnd = _audioPlayers.end();
    for (auto it = _audioPlayers.begin(); it != itEnd; ++it)
    {
        it->second->stop();
    }
    _audioPlayers.clear();
    _audioPathIDMap.clear();
}

void AudioEngine::uncache(const std::string &filePath)
{

}

void AudioEngine::uncacheAll()
{
//    stopAll();
//    _audioEngineImpl->uncacheAll();
}

float AudioEngine::getDuration(int audioID)
{
    auto it = _audioPlayers.find(audioID);
    if (it != _audioPlayers.end())
    {
//        if (it->second.duration == TIME_UNKNOWN)
//        {
//            it->second.duration = _audioEngineImpl->getDuration(audioID);
//        }
//        return it->second.duration;
        return it->second->getDuration();
    }

    return TIME_UNKNOWN;
}

bool AudioEngine::setCurrentTime(int audioID, float time)
{
    auto it = _audioPlayers.find(audioID);
    if (it != _audioPlayers.end()) {
        return it->second->setCurrentTime(time);
    }

    return false;
}

float AudioEngine::getCurrentTime(int audioID)
{
    auto it = _audioPlayers.find(audioID);
    if (it != _audioPlayers.end()) {
        return it->second->getCurrentTime();
    }
    return 0.0f;
}

void AudioEngine::setFinishCallback(int audioID, const std::function<void (int, const std::string &)> &callback)
{
    auto it = _audioPlayers.find(audioID);
    if (it != _audioPlayers.end()){
        it->second->setFinishCallback(callback);
    }
}

bool AudioEngine::setMaxAudioInstance(int maxInstances)
{
    if (maxInstances > 0 && maxInstances <= MAX_AUDIOINSTANCES) {
        _maxInstances = maxInstances;
        return true;
    }

    return false;
}

bool AudioEngine::isLoop(int audioID)
{
    auto tmpIterator = _audioPlayers.find(audioID);
    if (tmpIterator != _audioPlayers.end())
    {
        return tmpIterator->second->getLoop();
    }

    log("AudioEngine::isLoop-->The audio instance %d is non-existent", audioID);
    return false;
}

float AudioEngine::getVolume(int audioID)
{
    auto tmpIterator = _audioPlayers.find(audioID);
    if (tmpIterator != _audioPlayers.end())
    {
        return tmpIterator->second->getVolume();
    }

    log("AudioEngine::getVolume-->The audio instance %d is non-existent", audioID);
    return 0.0f;
}

AudioEngine::AudioState AudioEngine::getState(int audioID)
{
    auto tmpIterator = _audioPlayers.find(audioID);
    if (tmpIterator != _audioPlayers.end())
    {
        return tmpIterator->second.state;
    }

    return AudioState::ERROR;
}

AudioProfile* AudioEngine::getProfile(int audioID)
{
////    auto it = _audioIDInfoMap.find(audioID);
////    if (it != _audioIDInfoMap.end())
////    {
//        return &it->second.profileHelper->profile;
////    }

    return nullptr;
}

AudioProfile* AudioEngine::getDefaultProfile()
{
    if (_defaultProfileHelper == nullptr)
    {
        _defaultProfileHelper = new (std::nothrow) ProfileHelper();
    }

    return &_defaultProfileHelper->profile;
}

AudioProfile* AudioEngine::getProfile(const std::string &name)
{
    auto it = _audioPathProfileHelperMap.find(name);
    if (it != _audioPathProfileHelperMap.end()) {
        return &it->second.profile;
    } else {
        return nullptr;
    }
}

void AudioEngine::preload(const std::string& filePath, std::function<void(bool isSuccess)> callback)
{
    if (!isEnabled())
    {
        callback(false);
        return;
    }

    lazyInit();

    if (_audioEngineImpl)
    {
        if (!FileUtils::getInstance()->isFileExist(filePath)){
            if (callback)
            {
                callback(false);
            }
            return;
        }

        _audioEngineImpl->preload(filePath, callback);
    }
}

void AudioEngine::addTask(const std::function<void()>& task)
{
    lazyInit();

//    if (_audioEngineImpl && s_threadPool)
//    {
//        s_threadPool->addTask(task);
//    }
}

int AudioEngine::getPlayingAudioCount()
{
    return static_cast<int>(_audioPlayers.size());
}

void AudioEngine::setEnabled(bool isEnabled)
{
    if (_isEnabled != isEnabled)
    {
        _isEnabled = isEnabled;

        if (!_isEnabled)
        {
            stopAll();
        }
    }
}

bool AudioEngine::isEnabled()
{
    return _isEnabled;
}

#endif

