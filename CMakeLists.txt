cmake_minimum_required(VERSION 3.26)
project(ai_homework)

set(CMAKE_CXX_STANDARD 17)

add_executable(ai_homework main.cpp
        dfs/DfsSolution.h
        uniform_cost/UniformCost.h
        includer.h
        a_Search/ASearch.h
)
