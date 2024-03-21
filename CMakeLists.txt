cmake_minimum_required(VERSION 3.27)
project(TimeOffOptimizer)

set(CMAKE_CXX_STANDARD 17)

add_executable(TimeOffOptimizer main.cpp
        employee.h
        employee.cpp
        date.h
        date.cpp
        planner.h
        planner.cpp
        vacation.h
)
