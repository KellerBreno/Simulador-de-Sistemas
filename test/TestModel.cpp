//
// Created by brenokeller on 11/8/18.
//

#include <iostream>
#include <cassert>
#include <cmath>
#include "TestModel.h"
#include "../src/ModelImpl.h"
#include "../src/SystemImpl.h"
#include "../src/FlowExp.h"
#include "../src/FlowLog.h"

void TestModel::run() {
    cout << "============ Testes Unitarios Model =============" << endl;
    TestModel::unitConstructor();
    TestModel::unitAdd();
    TestModel::unitGetFlow();
    TestModel::unitGetSystem();
    TestModel::unitGetName();
    TestModel::unitSetName();
    TestModel::unitRemove();
    TestModel::unitSimulate();
    TestModel::unitReport();
    cout << "=================================================" << endl;
}

void TestModel::unitConstructor() {
    cout << "Constructor: ";
    Model *model = new ModelImpl("model");

    assert(model->getName() == "model");
    // TODO Testes para iterators

    delete model;
    cout << "OK" << endl;
}

void TestModel::unitSimulate() {
    cout << "simulate: ";
    System *p1 = new SystemImpl("p1", 50);
    System *p2 = new SystemImpl("p2", 0);

    Flow *exp = new FlowExp("exp", 0.01);
    exp->setSource(p1);
    exp->setTarget(p2);

    Model *model = new ModelImpl("teste");
    model->add(p1);
    model->add(p2);
    model->add(exp);

    model->simulate(1, 10);

    assert(fabs(p1->getValue() - 45.2191) < 0.0001);
    assert(fabs(p2->getValue() - 4.7809) < 0.0001);

    delete model;
    cout << "OK" << endl;
}

void TestModel::unitAdd() {
    cout << "add: ";
    Model *model = new ModelImpl("model");
    System *s1 = new SystemImpl("s1", 0);
    Flow *f1 = new FlowLog("f1");
    model->add(s1);
    model->add(f1);

    System *s2 = model->getSystem("s1");
    assert(s2 != nullptr);
    assert(s2 == s1);

    Flow *f2 = model->getFlow("f1");
    assert(f2 != nullptr);
    assert(f2 == f1);

    delete model;
    cout << "OK" << endl;
}

void TestModel::unitGetFlow() {
    cout << "getFlow: ";
    Model *model = new ModelImpl("modelo");
    Flow *f1 = new FlowLog("log");

    model->add(f1);
    Flow *f2 = model->getFlow("log");

    assert(f2 != nullptr);
    assert(f1 == f2);

    cout << "OK" << endl;
}

void TestModel::unitGetSystem() {
    cout << "getSystem: ";
    Model *model = new ModelImpl("modelo");
    System *s1 = new SystemImpl("s1", 0);

    model->add(s1);
    System *s2 = model->getSystem("s1");

    assert(s2 != nullptr);
    assert(s1 == s2);

    cout << "OK" << endl;
}

void TestModel::unitRemove() {
    cout << "remove: ";
    Model *model = new ModelImpl("model");
    System *s1 = new SystemImpl("s1", 0);
    System *s2 = new SystemImpl("s2", 0);
    Flow *f1 = new FlowLog("f1");
    Flow *f2 = new FlowLog("f2");
    model->add(s1);
    model->add(s2);
    model->add(f1);
    model->add(f2);

    model->remove("s1");
    System *s3 = model->getSystem("s1");
    assert(s3 == nullptr);
    assert(s3 != s1);

    model->remove("f1");
    Flow *f3 = model->getFlow("f1");
    assert(f3 == nullptr);
    assert(f3 != f1);

    delete model;
    cout << "OK" << endl;
}

void TestModel::unitGetName() {
    cout << "getName: ";
    Model *model = new ModelImpl("model");
    assert(model->getName() == "model");
    cout << "OK" << endl;
}

void TestModel::unitSetName() {
    cout << "setName: ";
    Model *model = new ModelImpl("model");
    model->setName("modelnew");
    assert(model->getName() == "modelnew");
    cout << "OK" << endl;
}

void TestModel::unitReport() {
    cout << "report: ";
    System *p1 = new SystemImpl("p1", 50);
    System *p2 = new SystemImpl("p2", 0);

    Flow *exp = new FlowExp("exp", 0.01);
    exp->setSource(p1);
    exp->setTarget(p2);

    Model *model = new ModelImpl("teste");
    model->add(p1);
    model->add(p2);
    model->add(exp);

    model->simulate(1, 10);

    string expected = "===========================================================\n"
                      "Modelo: teste\n"
                      "----------------------- Sistemas --------------------------\n"
                      "Sistema: p1 - 45.2191\n"
                      "Sistema: p2 - 4.7809\n"
                      "------------------------ Fluxos ---------------------------\n"
                      "Fluxo: exp\n"
                      "===========================================================\n";
    string actual = model->report();
    assert(expected == actual);
    delete model;

    model = new ModelImpl("vazio");
    expected = "===========================================================\n"
               "Modelo: vazio\n"
               "----------------------- Sistemas --------------------------\n"
               "------------------------ Fluxos ---------------------------\n"
               "===========================================================\n";
    actual = model->report();
    assert(expected == actual);

    cout << "OK" << endl;
}