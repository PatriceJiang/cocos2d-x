
set(COCOS_AUDIO_SRC
    audio/AudioEngine.cpp
    )

if(WINDOWS)

    set(COCOS_AUDIO_PLATFORM_HEADER
        audio/win32/AudioDecoderManager.h
        audio/win32/AudioDecoder.h
        audio/win32/MciPlayer.h
        audio/win32/AudioPlayer.h
        audio/win32/AudioDecoderOgg.h
        audio/win32/AudioMacros.h
        audio/win32/AudioEngine-win32.h
        audio/win32/AudioDecoderMp3.h
        audio/win32/AudioCache.h
        )

    set(COCOS_AUDIO_PLATFORM_SRC
        audio/win32/SimpleAudioEngine.cpp
        audio/win32/MciPlayer.cpp
        audio/win32/MciPlayer.h
        audio/win32/AudioEngine-win32.cpp
        audio/win32/AudioCache.cpp
        audio/win32/AudioPlayer.cpp
        audio/win32/AudioDecoder.cpp
        audio/win32/AudioDecoderManager.cpp
        audio/win32/AudioDecoderMp3.cpp
        audio/win32/AudioDecoderOgg.cpp
        )

elseif(ANDROID)

    set(COCOS_AUDIO_PLATFORM_HEADER
        audio/android/IAudioPlayer.h
        audio/android/AudioDecoder.h
        audio/android/tinysndfile.h
        audio/android/mp3reader.h
        audio/android/cutils/bitops.h
        audio/android/cutils/log.h
        audio/android/ccdandroidUtils.h
        audio/android/AudioDecoderOgg.h
        audio/android/audio_utils/include/audio_utils/minifloat.h
        audio/android/audio_utils/include/audio_utils/primitives.h
        audio/android/audio_utils/include/audio_utils/format.h
        audio/android/audio_utils/private/private.h
        audio/android/AudioDecoderWav.h
        audio/android/AudioDecoderMp3.h
        audio/android/jni/cddandroidAndroidJavaEngine.h
        audio/android/AudioEngine-inl.h
        audio/android/AudioPlayer.h
        audio/android/AudioCache.h
        audio/android/AudioDecoderManager.h
        )

    set(COCOS_AUDIO_PLATFORM_SRC
        audio/android/cddSimpleAudioEngine.cpp
        audio/android/ccdandroidUtils.cpp
        audio/android/jni/cddandroidAndroidJavaEngine.cpp
        audio/android/AudioEngine-inl.cpp
        audio/android/AudioDecoder.cpp
        audio/android/AudioDecoderOgg.cpp
        audio/android/AudioDecoderMp3.cpp
        audio/android/AudioDecoderWav.cpp
        audio/android/audio_utils/format.c
        audio/android/audio_utils/minifloat.cpp
        audio/android/audio_utils/primitives.c
        audio/android/mp3reader.cpp
        audio/android/tinysndfile.cpp
        audio/android/AudioPlayer.cpp
        audio/android/AudioCache.cpp
        audio/android/AudioDecoderManager.cpp
        )

elseif(LINUX)
    set(COCOS_AUDIO_PLATFORM_HEADER
        audio/linux/AudioEngine-linux.h
        )

    set(COCOS_AUDIO_PLATFORM_SRC
        audio/linux/SimpleAudioEngine.cpp
        audio/linux/AudioEngine-linux.h
        audio/linux/AudioEngine-linux.cpp
        )

elseif(APPLE)
    # common
    set(COCOS_AUDIO_PLATFORM_HEADER
        audio/apple/AudioDecoder.h
        audio/apple/AudioPlayer.h
        audio/apple/AudioMacros.h
        audio/apple/AudioCache.h
        audio/apple/AudioEngine-inl.h
        )
    set(COCOS_AUDIO_PLATFORM_SRC
        audio/apple/AudioCache.mm
        audio/apple/AudioDecoder.mm
        audio/apple/AudioEngine-inl.mm
        audio/apple/AudioPlayer.mm
        )
    # split it in _C and non C
    # because C files needs to be compiled with C compiler and not C++
    # compiler
    if(MACOSX)
        set(COCOS_AUDIO_PLATFORM_HEADER
            ${COCOS_AUDIO_PLATFORM_HEADER}
            audio/mac/CDConfig.h
            audio/mac/SimpleAudioEngine_objc.h
            audio/mac/CDOpenALSupport.h
            audio/mac/CDXMacOSXSupport.h
            audio/mac/CDAudioManager.h
            audio/mac/CocosDenshion.h
            )
        set(COCOS_AUDIO_PLATFORM_SRC_C
            audio/mac/CDAudioManager.m
            audio/mac/CDOpenALSupport.m
            audio/mac/CocosDenshion.m
            audio/mac/SimpleAudioEngine_objc.m
            )
        set(COCOS_AUDIO_PLATFORM_SRC
            ${COCOS_AUDIO_PLATFORM_SRC_C}
            ${COCOS_AUDIO_PLATFORM_SRC}
            audio/mac/SimpleAudioEngine.mm
            audio/mac/CDXMacOSXSupport.mm
            )
    elseif(IOS)
        set(COCOS_AUDIO_PLATFORM_HEADER
            ${COCOS_AUDIO_PLATFORM_HEADER}
            audio/ios/CDConfig.h
            audio/ios/SimpleAudioEngine_objc.h
            audio/ios/CDOpenALSupport.h
            audio/ios/CDAudioManager.h
            audio/ios/CocosDenshion.h
            )
        set(COCOS_AUDIO_PLATFORM_SRC_C
            audio/ios/CDAudioManager.m
            audio/ios/CDOpenALSupport.m
            audio/ios/CocosDenshion.m
            audio/ios/SimpleAudioEngine_objc.m
            )
        set(COCOS_AUDIO_PLATFORM_SRC
            ${COCOS_AUDIO_PLATFORM_SRC_C}
            ${COCOS_AUDIO_PLATFORM_SRC}
            audio/ios/SimpleAudioEngine.mm
            )
    endif()

    set_source_files_properties(
            ${COCOS_AUDIO_PLATFORM_SRC_C}
            PROPERTIES LANGUAGE C
    )
endif()

set(COCOS_AUDIO_HEADER
    audio/include/AudioEngine.h
    audio/include/Export.h
    audio/include/SimpleAudioEngine.h
    ${COCOS_AUDIO_PLATFORM_HEADER}
    )
list(APPEND COCOS_AUDIO_SRC ${COCOS_AUDIO_PLATFORM_SRC})
