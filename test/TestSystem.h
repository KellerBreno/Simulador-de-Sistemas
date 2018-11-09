//
// Created by brenokeller on 11/6/18.
//

#ifndef SIMULADOR_TESTSYSTEM_H
#define SIMULADOR_TESTSYSTEM_H

#include <cassert>

class TestSystem {
public:
    static void run();

private:
    static void unitConstructor();

    static void unitCopyConstructor();

    static void unitOperator();

    static void unitGetValue();

    static void unitSetValue();

    static void unitGetName();

    static void unitSetName();
};


#endif //SIMULADOR_TESTSYSTEM_H
