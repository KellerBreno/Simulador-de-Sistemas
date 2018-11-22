//
// Created by brenokeller on 11/8/18.
//

#include <iostream>
#include <cassert>
#include <cmath>
#include "TestModel.h"
#include "../src/ModelImpl.h"
#include "../src/SystemImpl.h"
#include "../FlowExp.h"
#include "../FlowLog.h"

void TestModel::run() {
    cout << "============ Testes Unitários Model =============" << endl;
    TestModel::unitConstructor();
    TestModel::unitEqual();
    TestModel::unitCopyConstructor();
    TestModel::unitOperator();
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

    System *s = model->getSystem("s");
    assert(s == nullptr);
    Flow *f = model->getFlow("f");
    assert(f == nullptr);

    Model *newModel = new ModelImpl("");
    assert(newModel->getName().empty());

    System *ns = newModel->getSystem("s");
    assert(ns == nullptr);
    Flow *nf = newModel->getFlow("f");
    assert(nf == nullptr);

    delete (ModelImpl *) model;
    delete (ModelImpl *) newModel;

    cout << "OK" << endl;
}

void TestModel::unitCopyConstructor() {
    cout << "Copy Constructor: ";

    ModelImpl *model = new ModelImpl("model");
    System *s1 = new SystemImpl("s1", 0);
    System *s2 = new SystemImpl("s2", 0);
    Flow *f1 = new FlowLog("f1");
    Flow *f2 = new FlowExp("f2", 0.01);
    model->add(s1);
    model->add(s2);
    model->add(f1);
    model->add(f2);

    ModelImpl *newModel = new ModelImpl("newModel");
    (*newModel) = (*model);
    assert(newModel != model);

    System *s3 = newModel->getSystem("s1");
    assert(s3 != nullptr);
    assert((*s3) == (*s1));

    System *s4 = newModel->getSystem("s2");
    assert(s4 != nullptr);
    assert((*s4) == (*s2));

    Flow *f3 = newModel->getFlow("f1");
    assert(f3 != nullptr);
    assert((*f3) == (*f1));

    Flow *f4 = newModel->getFlow("f2");
    assert(f4 != nullptr);
    assert((*f4) == (*f2));

    assert(model->getName() == newModel->getName());

    delete model;
    delete newModel;
    delete (SystemImpl *) s1;
    delete (SystemImpl *) s2;
    delete (FlowLog *) f1;
    delete (FlowExp *) f2;

    cout << "OK" << endl;
}

void TestModel::unitOperator() {
    cout << "operator=: ";

    ModelImpl *model = new ModelImpl("model");
    System *s1 = new SystemImpl("s1", 0);
    System *s2 = new SystemImpl("s2", 0);
    Flow *f1 = new FlowLog("f1");
    Flow *f2 = new FlowExp("f2", 0.01);
    model->add(s1);
    model->add(s2);
    model->add(f1);
    model->add(f2);

    ModelImpl *newModel = new ModelImpl("newModel");
    (*newModel) = (*model);
    assert(newModel != model);

    System *s3 = newModel->getSystem("s1");
    assert(s3 != nullptr);
    assert((*s3) == (*s1));

    System *s4 = newModel->getSystem("s2");
    assert(s4 != nullptr);
    assert((*s4) == (*s2));

    Flow *f3 = newModel->getFlow("f1");
    assert(f3 != nullptr);
    assert((*f3) == (*f1));

    Flow *f4 = newModel->getFlow("f2");
    assert(f4 != nullptr);
    assert((*f4) == (*f2));

    assert(model->getName() == newModel->getName());

    delete model;
    delete newModel;
    delete (SystemImpl *) s1;
    delete (SystemImpl *) s2;
    delete (FlowLog *) f1;
    delete (FlowExp *) f2;

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

    System *np1 = new SystemImpl("p1", 50);
    System *np2 = new SystemImpl("p2", 0);

    Flow *nExp = new FlowExp("exp", 0.01);
    nExp->setSource(np1);
    nExp->setTarget(np2);

    Model *nModel = new ModelImpl("outro teste");
    nModel->add(np1);
    nModel->add(np2);
    nModel->add(nExp);
    nModel->simulate(1, 10, 1);

    assert(fabs(np1->getValue() - 45.2191) < 0.0001);
    assert(fabs(np2->getValue() - 4.7809) < 0.0001);

    assert(fabs(p1->getValue() - np1->getValue()) < 0.0001);
    assert(fabs(p2->getValue() - np2->getValue()) < 0.0001);

    delete (ModelImpl *) model;
    delete (ModelImpl *) nModel;
    delete (SystemImpl *) p1;
    delete (SystemImpl *) p2;
    delete (SystemImpl *) np1;
    delete (SystemImpl *) np2;
    delete (FlowExp *) exp;
    delete (FlowExp *) nExp;

    cout << "OK" << endl;
}

void TestModel::unitAdd() {
    cout << "add: ";

    Model *model = new ModelImpl("model");

    System *s1 = new SystemImpl("s1", 0);
    Flow *f1 = new FlowLog("f1");
    Flow *f2 = new FlowExp("f2", 1);
    model->add(s1);
    model->add(f1);
    model->add(f2);

    System *s2 = model->getSystem("s1");
    assert(s2 != nullptr);
    assert(s2 == s1);

    Flow *f3 = model->getFlow("f1");
    assert(f3 != nullptr);
    assert(f3 == f1);

    Flow *f4 = model->getFlow("f2");
    assert(f4 != nullptr);
    assert(f4 == f2);

    delete (ModelImpl *) model;
    delete (FlowLog *) f1;
    delete (FlowExp *) f2;
    delete (SystemImpl *) s1;

    cout << "OK" << endl;
}

void TestModel::unitGetFlow() {
    cout << "getFlow: ";

    Model *model = new ModelImpl("modelo");

    Flow *f = model->getFlow("l");
    assert(f == nullptr);

    Flow *f1 = new FlowLog("log");
    model->add(f1);

    Flow *f2 = model->getFlow("log");
    assert(f2 != nullptr);
    assert(f1 == f2);

    Flow *f3 = new FlowExp("exp", 1);
    model->add(f3);

    Flow *f4 = model->getFlow("exp");
    assert(f4 != nullptr);
    assert(f3 == f4);

    delete (ModelImpl *) model;
    delete (FlowLog *) f1;
    delete (FlowExp *) f3;

    cout << "OK" << endl;
}

void TestModel::unitGetSystem() {
    cout << "getSystem: ";

    Model *model = new ModelImpl("modelo");

    System *s = model->getSystem("s");
    assert(s == nullptr);

    System *s1 = new SystemImpl("s1", 0);
    model->add(s1);

    System *s2 = model->getSystem("s1");
    assert(s2 != nullptr);
    assert(s1 == s2);

    delete (ModelImpl *) model;
    delete (SystemImpl *) s1;

    cout << "OK" << endl;
}

void TestModel::unitRemove() {
    cout << "remove: ";

    Model *model = new ModelImpl("model");

    model->remove("s");
    System *s = model->getSystem("s");
    assert(s == nullptr);

    model->remove("f");
    Flow *f = model->getFlow("f");
    assert(f == nullptr);

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
    assert(s3 != s1);
    assert(s3 == nullptr);

    model->remove("f1");
    Flow *f3 = model->getFlow("f1");
    assert(f3 != f1);
    assert(f3 == nullptr);

    delete (ModelImpl *) model;
    delete (SystemImpl *) s1;
    delete (SystemImpl *) s2;
    delete (FlowLog *) f1;
    delete (FlowLog *) f2;

    cout << "OK" << endl;
}

void TestModel::unitGetName() {
    cout << "getName: ";

    Model *model = new ModelImpl("model");
    assert(model->getName() == "model");

    Model *newModel = new ModelImpl("");
    assert(newModel->getName().empty());

    delete (ModelImpl *) model;
    delete (ModelImpl *) newModel;

    cout << "OK" << endl;
}

void TestModel::unitSetName() {
    cout << "setName: ";

    Model *model = new ModelImpl("model");
    assert(model->getName() == "model");

    model->setName("modelnew");
    assert(model->getName() == "modelnew");

    model->setName("");
    assert(model->getName().empty());

    delete (ModelImpl *) model;

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

    delete (ModelImpl *) model;

    model = new ModelImpl("vazio");
    expected = "===========================================================\n"
               "Modelo: vazio\n"
               "----------------------- Sistemas --------------------------\n"
               "------------------------ Fluxos ---------------------------\n"
               "===========================================================\n";
    actual = model->report();
    assert(expected == actual);

    delete (ModelImpl *) model;
    delete (SystemImpl *) p1;
    delete (SystemImpl *) p2;
    delete (FlowExp *) exp;

    cout << "OK" << endl;
}

void TestModel::unitEqual() {
    cout << "operator==: ";

    Model *m1 = new ModelImpl("model1");
    Model *m2 = new ModelImpl("model2");
    assert((*m1) != (*m2));

    ModelImpl *m3 = dynamic_cast<ModelImpl *>(m1);
    ModelImpl *m4 = dynamic_cast<ModelImpl *>(m2);
    (*m4) = (*m3);
    assert((*m3) == (*m4));

    delete m3;
    delete m4;

    ModelImpl *m5 = new ModelImpl("model3");
    ModelImpl *m6 = new ModelImpl("model4");

    System *s1 = new SystemImpl("s1", 0);
    System *s2 = new SystemImpl("s2", 0);
    m5->add(s1);
    m6->add(s2);
    assert((*m5) != (*m6));

    m5->add(s2);
    (*m6) = (*m5);
    assert((*m5) == (*m6));

    delete m5;
    delete m6;
    delete (SystemImpl *) s1;
    delete (SystemImpl *) s2;

    cout << "OK" << endl;
}