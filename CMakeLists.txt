cmake_minimum_required(VERSION 3.12)
project(Simulador)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulador
        main.cpp
        src/Model.h
        src/System.h
        src/Flow.h
        src/ModelImpl.cpp
        src/ModelImpl.h
        src/SystemImpl.cpp
        src/SystemImpl.h
        src/FlowExp.cpp
        src/FlowExp.h
        src/FlowLog.cpp
        src/FlowLog.h
        test/TestVensim.cpp
        test/TestVensim.h
        test/TestSystem.cpp
        test/TestSystem.h)