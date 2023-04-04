cmake_minimum_required(VERSION 3.4.0)

project(uebung07)


add_library(canvas canvas.cc canvas.hh)
add_library(pgm pgm.cc pgm.hh)
add_library(point point.cc point.hh)
add_executable(pixelgraphiken plot.cc)

target_link_libraries(pixelgraphiken pgm point canvas)