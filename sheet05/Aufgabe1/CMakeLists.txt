# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name to vectors
project(vectors LANGUAGES CXX)

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

# add library
add_library(io io.cc)
add_library(statistics statistics.cc)

# Create executable programs
add_executable(normal.out normal.cc)
add_executable(uniform.out uniform.cc)
add_executable(readvector.out readvector.cc)
add_executable(test_mean.out test_mean.cc)
add_executable(test_median.out test_median.cc)

# link library to executable
target_link_libraries(normal.out PUBLIC io statistics)
target_link_libraries(uniform.out PUBLIC io statistics)
target_link_libraries(readvector.out PUBLIC io statistics)
target_link_libraries(test_mean.out PUBLIC io statistics)
target_link_libraries(test_median.out PUBLIC io statistics)

# make tests
enable_testing()
add_test(NAME test_mean COMMAND test_mean.out)
add_test(NAME test_median COMMAND test_median.out)

# for release use       cmake --CMAKE_BUILD_TYPE=Release ..