//
// Created by brenokeller on 11/8/18.
//

#ifndef SIMULADOR_TESTMODEL_H
#define SIMULADOR_TESTMODEL_H


class TestModel {
public:
    static void run();

private:
    static void unitConstructor();

    static void unitSimulate();

    static void unitAdd();

    static void unitGetFlow();

    static void unitGetSystem();

    static void unitRemove();

    static void unitGetName();

    static void unitSetName();

    static void unitReport();

};


#endif //SIMULADOR_TESTMODEL_H
