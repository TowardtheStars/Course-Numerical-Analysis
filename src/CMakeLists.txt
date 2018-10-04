cmake_minimum_required(VERSION 3.12)
project(NumericalAnalysis)

set(CMAKE_CXX_STANDARD 11)

add_executable(Homework01 homework_01.cpp)
target_link_libraries(Homework01 libanalysis)

add_executable(Homework02 homework_02.cpp)
target_link_libraries(Homework02 libanalysis)