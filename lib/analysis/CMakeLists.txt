cmake_minimum_required(VERSION 3.12)
project(NumericalAnalysis)

set(CMAKE_CXX_STANDARD 11)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_library(libanalysis ${DIR_SRCS})
set_target_properties(libanalysis PROPERTIES OUTPUT_NAME "analysis")