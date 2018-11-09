//
// Created by brenokeller on 11/8/18.
//

#include <iostream>
#include <cassert>
#include <cmath>
#include "TestFlow.h"
#include "../src/FlowExp.h"
#include "../src/FlowLog.h"
#include "../src/SystemImpl.h"

void TestFlow::run() {
    cout << "============= Testes Unitarios Flow =============" << endl;
    TestFlow::unitConstructor();
    TestFlow::unitGetName();
    TestFlow::unitSetName();
    TestFlow::unitGetSource();
    TestFlow::unitSetSource();
    TestFlow::unitGetTarget();
    TestFlow::unitSetTarget();
    TestFlow::unitExecute();
    cout << "=================================================" << endl;
}

void TestFlow::unitConstructor() {
    cout << "Construtor: ";
    Flow *log = new FlowLog("log");
    Flow *exp = new FlowExp("exp", 0.01);

    assert(log->getName() == "log");
    assert(log->getSource() == nullptr);
    assert(log->getTarget() == nullptr);

    assert(exp->getName() == "exp");
    assert(exp->getSource() == nullptr);
    assert(exp->getTarget() == nullptr);

    delete log;
    delete exp;
    cout << "OK" << endl;
}

void TestFlow::unitExecute() {
    cout << "Execute: ";
    System *s1 = new SystemImpl("s1", 50);

    Flow *log = new FlowLog("log");
    log->setTarget(s1);

    Flow *exp = new FlowExp("exp", 0.01);
    exp->setSource(s1);

    assert(fabs(log->execute() - 0.1429) < 0.0001);
    assert(fabs(exp->execute() - 0.5) < 0.0001);

    delete log;
    delete exp;
    delete s1;
    cout << "OK" << endl;
}

void TestFlow::unitGetSource() {
    cout << "getSource: ";
    Flow *log = new FlowLog("log");
    Flow *exp = new FlowExp("exp", 0.01);

    assert(log->getSource() == nullptr);
    assert(exp->getSource() == nullptr);

    delete log;
    delete exp;
    cout << "OK" << endl;
}

void TestFlow::unitSetSource() {
    cout << "setSource: ";
    System *s1 = new SystemImpl("s1", 50);

    Flow *log = new FlowLog("log");
    log->setSource(s1);

    Flow *exp = new FlowExp("exp", 0.01);
    exp->setSource(s1);

    assert(log->getSource() == s1);
    assert(exp->getSource() == s1);

    delete log;
    delete exp;
    delete s1;
    cout << "OK" << endl;
}

void TestFlow::unitGetTarget() {
    cout << "getTarget: ";
    Flow *log = new FlowLog("log");
    Flow *exp = new FlowExp("exp", 0.01);

    assert(log->getTarget() == nullptr);
    assert(exp->getTarget() == nullptr);

    delete log;
    delete exp;
    cout << "OK" << endl;
}

void TestFlow::unitSetTarget() {
    cout << "setTarget: ";
    System *s1 = new SystemImpl("s1", 50);

    Flow *log = new FlowLog("log");
    log->setTarget(s1);

    Flow *exp = new FlowExp("exp", 0.01);
    exp->setTarget(s1);

    assert(log->getTarget() == s1);
    assert(exp->getTarget() == s1);

    delete log;
    delete exp;
    delete s1;
    cout << "OK" << endl;
}

void TestFlow::unitGetName() {
    cout << "getName: ";
    Flow *log = new FlowLog("log");
    Flow *exp = new FlowExp("exp", 0.01);

    assert(log->getName() == "log");
    assert(exp->getName() == "exp");

    delete log;
    delete exp;
    cout << "OK" << endl;
}

void TestFlow::unitSetName() {
    cout << "setName: ";
    Flow *log = new FlowLog("log");
    log->setName("lognew");
    Flow *exp = new FlowExp("exp", 0.01);
    exp->setName("expnew");

    assert(log->getName() == "lognew");
    assert(exp->getName() == "expnew");

    delete log;
    delete exp;
    cout << "OK" << endl;
}
