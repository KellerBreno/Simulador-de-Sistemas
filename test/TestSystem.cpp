//
// Created by brenokeller on 11/6/18.
//

#include <iostream>
#include "TestSystem.h"
#include "../src/SystemImpl.h"

void TestSystem::run() {
    cout << "============ Testes Unitarios System ============" << endl;
    TestSystem::unitConstructor();
    TestSystem::unitGetValue();
    TestSystem::unitSetValue();
    TestSystem::unitGetName();
    TestSystem::unitSetName();
    cout << "=================================================" << endl;
}

void TestSystem::unitConstructor() {
    cout << "Construtor: ";
    System *t = new SystemImpl("t", 0);

    assert(t->getName().compare("t") == 0);
    assert(t->getValue() - 0 == 0);

    delete t;
    cout << "OK" << endl;
}

void TestSystem::unitGetValue() {
    cout << "getValue: ";
    System *t1 = new SystemImpl("t1", 0);
    System *t2 = new SystemImpl("t2", (1 / 3));

    assert(t1->getValue() - 0 < 0.0001);
    assert(t2->getValue() - (1 / 3) < 0.0001);

    delete t1;
    delete t2;
    cout << "OK " << endl;
}

void TestSystem::unitSetValue() {
    cout << "setValue: ";
    System *t1 = new SystemImpl("t", 0);
    t1->setValue(2);

    assert(t1->getValue() - 2 < 0.0001);

    delete t1;
    cout << "OK " << endl;
}

void TestSystem::unitGetName() {
    cout << "getName: ";
    System *t1 = new SystemImpl("t1", 0);
    System *t2 = new SystemImpl("t2", (1 / 3));

    assert(t1->getName() == "t1");
    assert(t2->getName() == "t2");

    delete t1;
    delete t2;
    cout << "OK " << endl;
}

void TestSystem::unitSetName() {
    cout << "setName: ";
    System *t1 = new SystemImpl("t", 0);
    t1->setName("tnew");

    assert(t1->getName() == "tnew");

    delete t1;
    cout << "OK " << endl;
}

