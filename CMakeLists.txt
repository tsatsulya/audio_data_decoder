#cmake ../ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja

cmake_minimum_required(VERSION 3.5)

project(reader:3) 
add_executable(reader main.cpp audio_data_reader.cpp)

find_package(Flac REQUIRED)

target_link_libraries(reader PRIVATE FLAC::FLAC++)
target_include_directories(reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# find_package(libnyquist REQUIRED)
# target_link_libraries(reader PRIVATE libnyquist)