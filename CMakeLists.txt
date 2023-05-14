#cmake ../ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja

cmake_minimum_required(VERSION 3.5)

project(audio-data) 

add_executable(reader main.cpp audio_data_reader.cpp)

find_package(Flac REQUIRED)

target_link_libraries(reader PRIVATE FLAC::FLAC++)

find_package(jsoncpp REQUIRED)
target_include_directories(reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# find_package(libnyquist REQUIRED)
target_link_libraries(reader PUBLIC jsoncpp_lib)

add_library(audio-data SHARED
			audio_data_reader.cpp 
			audio_data.h)

target_include_directories(audio-data PRIVATE source)
set_target_properties(audio-data PROPERTIES PUBLIC_HEADER audio_data_reader.h)

target_link_libraries(reader PUBLIC audio-data)
