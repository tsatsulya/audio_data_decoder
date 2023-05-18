#cmake ../ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja

find_package(Flac REQUIRED)
find_package(jsoncpp REQUIRED)

add_library(audio_data STATIC src/audio_data_reader.cpp)
target_include_directories(audio_data PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
