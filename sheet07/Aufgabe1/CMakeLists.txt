# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)

# Start project and set its name to vectors
project(vectors LANGUAGES CXX)

# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)

add_executable(test_Coordinates1D.out test_1D.cc)
add_executable(test_Coordinates3D.out test_3D.cc)

# make tests
enable_testing()
add_test(NAME test_Coordinates1D COMMAND test_Coordinates1D.out)
add_test(NAME test_Coordinates3D COMMAND test_Coordinates3D.out)

# for release use       cmake --CMAKE_BUILD_TYPE=Release ..
