cmake_minimum_required (VERSION 3.7)
project (Raspiano)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++17")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lstdc++fs")
link_libraries(stdc++fs)
link_libraries(dl)

set(VST_PATH /home/chris/Downloads/VST_SDK)
add_library(vst_sdk STATIC IMPORTED GLOBAL)
set_target_properties(vst_sdk PROPERTIES IMPORTED_LOCATION ${VST_PATH}/sdk_build/lib/Debug/libsdk.a)
add_library(vst_base STATIC IMPORTED GLOBAL)
set_target_properties(vst_base PROPERTIES IMPORTED_LOCATION ${VST_PATH}/sdk_build/lib/Debug/libbase.a)
add_library(vst_audiohost STATIC IMPORTED GLOBAL)
set_target_properties(vst_audiohost PROPERTIES IMPORTED_LOCATION ${VST_PATH}/sdk_build/lib/Debug/libaudiohost.a)

add_executable(Raspiano run_host.cpp minimal_host.cpp vst_module.cpp) 

include_directories(${VST_PATH}/VST3_SDK)
target_link_libraries(Raspiano vst_sdk vst_base vst_audiohost)

