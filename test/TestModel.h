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

    // static void unitCopyConstructor();

    // static void unitOperator();

    static void unitSimulate();

    // Métodos protected
    //static void unitAdd();

    static void unitGetFlow();

    static void unitGetSystem();

    static void unitGetName();

    static void unitSetName();

    static void unitReport();

    // Dependente da copia de modelos
    // static void unitEqualDifferent();

    static void unitDeleteSystem();

    static void unitDeleteFlow();

    static void unitCreateSystem();

    static void unitCreateFlow();

    static void unitCreateModel();

    static void unitDeleteModel();

};

#endif //SIMULADOR_TESTMODEL_H
