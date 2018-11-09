//
// Created by brenokeller on 11/8/18.
//

#ifndef SIMULADOR_TESTFLOW_H
#define SIMULADOR_TESTFLOW_H

#include "../src/Flow.h"

class TestFlow {
public:
    static void run();

private:
    static void unitConstructor();

    static void unitExecute();

    static void unitGetSource();

    static void unitSetSource() ;

    static void unitGetTarget() ;

    static void unitSetTarget();

    static void unitGetName();

    static void unitSetName();
};


#endif //SIMULADOR_TESTFLOW_H
