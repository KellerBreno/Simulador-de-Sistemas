//
// Created by brenokeller on 11/6/18.
//

#include <iostream>
#include <cmath>
#include "TestSystem.h"
#include "../src/SystemImpl.h"

void TestSystem::run() {
    cout << "============ Testes Unitarios System ============" << endl;
    TestSystem::unitConstructor();
    TestSystem::unitCopyConstructor();
    TestSystem::unitOperator();
    TestSystem::unitGetValue();
    TestSystem::unitSetValue();
    TestSystem::unitGetName();
    TestSystem::unitSetName();
    cout << "=================================================" << endl;
}

void TestSystem::unitConstructor() {
    cout << "Construtor: ";
    System *t = new SystemImpl("t", 5);

    assert(t->getName() == "t");
    assert(fabs(t->getValue() - 5) < 0.0001);

    delete t;
    cout << "OK" << endl;
}

void TestSystem::unitCopyConstructor() {
    cout << "Copy Constructor: ";
    SystemImpl *system = new SystemImpl("s1", 0);
    SystemImpl *newSystem = new SystemImpl((*system));

    assert(system->getName() == newSystem->getName());
    assert(system->getValue() == newSystem->getValue());

    cout << "OK" << endl;
}

void TestSystem::unitOperator() {
    cout << "operator=: ";
    SystemImpl *system = new SystemImpl("s1", 0);
    SystemImpl *newSystem = new SystemImpl("s2", 50);
    (*newSystem) = (*system);

    assert(system != newSystem);
    assert(system->getName() == newSystem->getName());
    assert(system->getValue() == newSystem->getValue());

    cout << "OK" << endl;
}

void TestSystem::unitGetValue() {
    cout << "getValue: ";
    System *t1 = new SystemImpl("t1", 5);
    System *t2 = new SystemImpl("t2", (1 / 3));

    assert(fabs(t1->getValue() - 5) < 0.0001);
    assert(fabs(t2->getValue() - (1 / 3)) < 0.0001);

    cout << "OK " << endl;
}

void TestSystem::unitSetValue() {
    cout << "setValue: ";
    System *t1 = new SystemImpl("t", 0);
    t1->setValue(2);

    assert(fabs(t1->getValue() - 2) < 0.0001);

    cout << "OK " << endl;
}

void TestSystem::unitGetName() {
    cout << "getName: ";
    System *t1 = new SystemImpl("t1", 0);
    System *t2 = new SystemImpl("t2", 2);

    assert(t1->getName() == "t1");
    assert(t2->getName() == "t2");

    cout << "OK " << endl;
}

void TestSystem::unitSetName() {
    cout << "setName: ";
    System *t1 = new SystemImpl("t", 0);
    t1->setName("tnew");

    assert(t1->getName() == "tnew");

    cout << "OK " << endl;
}

