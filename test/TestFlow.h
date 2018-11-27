//
// Created by brenokeller on 11/8/18.
//

#ifndef SIMULADOR_TESTFLOW_H
#define SIMULADOR_TESTFLOW_H

class TestFlow {
public:
    static void run();

private:
    static void unitConstructor();

    static void unitCopyConstructor();

    static void unitOperator();

    static void unitExecute();

    static void unitGetSource();

    static void unitSetSource();

    static void unitGetTarget();

    static void unitSetTarget();

    static void unitGetName();

    static void unitSetName();

    static void unitEqualDifferent();

//    static void unitClone();
};

#endif //SIMULADOR_TESTFLOW_H
