cmake_minimum_required(VERSION 3.12)
project(NumericalAnalysis)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(src DIR_SRCS)

add_library(libutil ${DIR_SRCS})