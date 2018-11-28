/*!
* \file TestSystem.cpp
* Arquivo contendo a Implementação da Classe de testes de sistema
*
* \author Breno Keller
* \since 6/11/18
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include "TestSystem.h"
#include "../src/SystemImpl.h"

void TestSystem::run() {
    cout << "============ Testes Unitários System ============" << endl;
    TestSystem::unitConstructor();
    TestSystem::unitEqualDifferent();
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

    System *t1 = new SystemImpl("t", 5);
    assert(t1->getName() == "t");
    assert(fabs(t1->getValue() - 5) < 0.0001);

    System *t2 = new SystemImpl("", 0.54321);
    assert(t2->getName().empty());
    assert(fabs(t2->getValue() - 0.54321) < 0.0001);

    System *t3 = new SystemImpl("t3", (1 / 3));

    assert(t3->getName() == "t3");
    assert(fabs(t3->getValue() - (1 / 3)) < 0.0001);

    delete (SystemImpl *) t1;
    delete (SystemImpl *) t2;
    delete (SystemImpl *) t3;

    cout << "OK" << endl;
}

void TestSystem::unitCopyConstructor() {
    cout << "Copy Constructor: ";

    System *system = new SystemImpl("s1", 0);
    System *newSystem = new SystemImpl((*system));

    assert(newSystem != system);
    assert(system->getName() == newSystem->getName());
    assert(system->getValue() == newSystem->getValue());

    delete (SystemImpl *) system;
    delete (SystemImpl *) newSystem;

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

    delete system;
    delete newSystem;

    cout << "OK" << endl;
}

void TestSystem::unitGetValue() {
    cout << "getValue: ";

    System *t1 = new SystemImpl("t1", 5);
    assert(fabs(t1->getValue() - 5) < 0.0001);

    System *t2 = new SystemImpl("t2", (1 / 3));
    assert(fabs(t2->getValue() - (1 / 3)) < 0.0001);

    System *t3 = new SystemImpl("t3", 0.52345);
    assert(fabs(t3->getValue() - 0.52345) < 0.0001);

    delete (SystemImpl *) t1;
    delete (SystemImpl *) t2;
    delete (SystemImpl *) t3;

    cout << "OK " << endl;
}

void TestSystem::unitSetValue() {
    cout << "setValue: ";

    System *t1 = new SystemImpl("t", 0);
    assert(fabs(t1->getValue()) < 0.0001);

    t1->setValue(2);
    assert(fabs(t1->getValue() - 2) < 0.0001);

    t1->setValue(1 / 3);
    assert(fabs(t1->getValue() - (1 / 3)) < 0.0001);

    t1->setValue(0.52345);
    assert(fabs(t1->getValue() - 0.52345) < 0.0001);

    delete (SystemImpl *) t1;

    cout << "OK " << endl;
}

void TestSystem::unitGetName() {
    cout << "getName: ";

    System *t1 = new SystemImpl("t1", 0);
    assert(t1->getName() == "t1");

    System *t2 = new SystemImpl("t2", 2);
    assert(t2->getName() == "t2");

    System *t3 = new SystemImpl("", 0);
    assert(t3->getName().empty());

    delete (SystemImpl *) t1;
    delete (SystemImpl *) t2;
    delete (SystemImpl *) t3;

    cout << "OK " << endl;
}

void TestSystem::unitSetName() {
    cout << "setName: ";

    System *t1 = new SystemImpl("t", 0);
    assert(t1->getName() == "t");

    t1->setName("tnew");
    assert(t1->getName() == "tnew");

    t1->setName("");
    assert(t1->getName().empty());

    delete (SystemImpl *) t1;

    cout << "OK " << endl;
}

void TestSystem::unitEqualDifferent() {
    cout << "operator==: ";

    System *s1 = new SystemImpl("t1", 0);
    System *s2 = new SystemImpl("t2", 10);
    assert((*s1) != (*s2));

    SystemImpl *s3 = dynamic_cast<SystemImpl *>(s1);
    SystemImpl *s4 = dynamic_cast<SystemImpl *>(s2);
    (*s4) = (*s3);
    assert((*s3) == (*s4));

    delete s3;
    delete s4;

    cout << "OK" << endl;
}