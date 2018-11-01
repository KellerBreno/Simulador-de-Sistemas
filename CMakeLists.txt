cmake_minimum_required(VERSION 3.12)
project(Simulador)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulador main.cpp Model.h System.h Flow.h ModelImpl.cpp ModelImpl.h SystemImpl.cpp SystemImpl.h FlowExp.cpp FlowExp.h)