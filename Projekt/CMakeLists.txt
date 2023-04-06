cmake_minimum_required (VERSION 3.24)
project(Projekt )
set(CMAKE_CXX_STANDARD 14 LANGUAGES_CXX)

add_library(freq_functions frequencies_letters/freq_functions.cpp)
add_executable(Loesung_2 frequencies_letters/loesung_2.cpp)
target_link_libraries(Loesung_2 freq_functions)

add_library(wfreq frequencies_words/wfreq_functions.cc)
add_library(sanitize frequencies_words/sanitizeword.cc)
add_executable(Loesung_3 frequencies_words/loesung_3.cpp)
target_link_libraries(Loesung_3 wfreq)
target_link_libraries(wfreq sanitize)

add_library(histo_class histogramme/histogram.cpp)
add_library(io histogramme/io.cc)
add_executable(Loesung_1 histogramme/loesung_1.cpp)
target_link_libraries(Loesung_1 histo_class)
target_link_libraries(Loesung_1 io)
