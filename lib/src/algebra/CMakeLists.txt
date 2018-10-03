cmake_minimum_required(VERSION 3.12)
project(NumericalAnalysis)

set(CMAKE_CXX_STANDARD 11)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

add_library(libalgebra ${DIR_SRCS})
set_target_properties(libalgebra PROPERTIES OUTPUT_NAME "algebra")