#/****************************************************************************
# Copyright (c) 2014-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

set(cocos_root ../../..)

#platform
if(WIN32) # Win32
  set(PLATFORM_FOLDER win32)
elseif(APPLE)# osx or ios
  set(PLATFORM_FOLDER mac)
 # set(PLATFORM_SRC manual/platform/ios/JavaScriptObjCBridge.mm)
else() # Assume Linux
  set(PLATFORM_FOLDER linux)
endif()

set(JSBINDING_SRC
  #auto/jsb_cocos2dx_3d_auto.cpp
  auto/jsb_cocos2dx_3d_extension_auto.cpp
  auto/jsb_cocos2dx_audioengine_auto.cpp
  auto/jsb_cocos2dx_auto.cpp
  auto/jsb_cocos2dx_builder_auto.cpp
  auto/jsb_cocos2dx_experimental_video_auto.cpp
  auto/jsb_cocos2dx_experimental_webView_auto.cpp
  auto/jsb_cocos2dx_extension_auto.cpp
  #auto/jsb_cocos2dx_navmesh_auto.cpp
  #auto/jsb_cocos2dx_network_auto.cpp
  #auto/jsb_cocos2dx_physics3d_auto.cpp
  #auto/jsb_cocos2dx_spine_auto.cpp
  #auto/jsb_cocos2dx_studio_auto.cpp
  #auto/jsb_cocos2dx_ui_auto.cpp
  #manual/BaseJSAction.cpp
  #manual/JavaScriptJavaBridge.cpp
  manual/ScriptingCore.cpp
  #manual/jsb_box2d_manual.cpp
  manual/jsb_classtype.cpp
  manual/jsb_cocos2dx_extension_manual.cpp
  manual/jsb_cocos2dx_manual.cpp
  manual/jsb_conversions.cpp
  manual/jsb_global.cpp
  manual/jsb_helper.cpp
  manual/jsb_module_register.cpp
  manual/jsb_node.cpp
  manual/jsb_opengl_functions.cpp
  manual/jsb_opengl_manual.cpp
  manual/jsb_opengl_node.cpp
  manual/jsb_opengl_registration.cpp
  manual/jsb_socketio.cpp
  #manual/jsb_spine_manual.cpp
  #manual/jsb_websocket.cpp
  #manual/jsb_xmlhttprequest.cpp
  jswrapper/HandleObject.cpp
  jswrapper/MappingUtils.cpp
  jswrapper/RefCounter.cpp
  jswrapper/State.cpp
  jswrapper/Value.cpp
  jswrapper/config.cpp
  jswrapper/jsc/Class.hpp
  jswrapper/jsc/HelperMacros.h
  jswrapper/jsc/Utils.cpp
  jswrapper/jsc/PlatformUtils.h
  jswrapper/jsc/Object.cpp
  jswrapper/jsc/ScriptEngine.cpp
  jswrapper/jsc/Object.hpp
  jswrapper/jsc/ScriptEngine.hpp
  jswrapper/jsc/PlatformUtils.mm
  jswrapper/jsc/SeApi.h
  jswrapper/jsc/Class.cpp
  jswrapper/jsc/Utils.hpp
  jswrapper/jsc/Base.h
  ${cocos_root}/cocos/storage/local-storage/LocalStorage.cpp
  ${PLATFORM_SRC}
)

include_directories(
  ${cocos_root}/external/spidermonkey/include/${PLATFORM_FOLDER}
  ${cocos_root}/cocos
  ${cocos_root}/cocos/editor-support
  ${cocos_root}/extensions
  ${cocos_root}/external
  ${cocos_root}/cocos/scripting/js-bindings/jswrapper
  ${CHIPMUNK_INCLUDE_DIRS}
)

add_library(jscocos2d STATIC
  ${JSBINDING_SRC}
)

find_library(SPIDERMONKEY_LIBRARY NAMES js_static mozjs HINTS
  ${cocos_root}/external/spidermonkey/prebuilt/${PLATFORM_FOLDER}/${ARCH_DIR}
  ${cocos_root}/external/spidermonkey/prebuilt/${PLATFORM_FOLDER}
)

find_library(JSCORE JavaScriptCore REQUIRED)

message("SPIDERMONKEY_LIBRARY: ${SPIDERMONKEY_LIBRARY}")

add_subdirectory(${cocos_root}/external/xxtea ExternalTea)

target_link_libraries(jscocos2d
  sqlite3
 # ${SPIDERMONKEY_LIBRARY}
  xxhash
  ${JSCORE}
  ext_xxtea
)
message(STATUS "---------------- ${JSCORE}")

set_target_properties(jscocos2d
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

if(USE_BULLET)
  include_directories(${BULLET_INCLUDE_DIRS})
endif()
