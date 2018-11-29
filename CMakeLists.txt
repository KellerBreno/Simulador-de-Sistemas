cmake_minimum_required(VERSION 3.12)
project(Simulador)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulador
        main.cpp
        test/TestVensim.cpp
        test/TestVensim.h
        test/TestSystem.cpp
        test/TestSystem.h
        test/TestFlow.cpp
        test/TestFlow.h
        test/TestModel.cpp
        test/TestModel.h
        src/Model.h
        src/System.h
        src/Flow.h
        src/ModelImpl.cpp
        src/ModelImpl.h
        src/SystemImpl.cpp
        src/SystemImpl.h
        src/FlowImpl.cpp
        src/FlowImpl.h
        src/HandleBody.h
        src/SystemHandle.cpp
        src/SystemHandle.h)