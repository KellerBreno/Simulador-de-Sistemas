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
    TestFlow::unitCopyConstructor();
    TestFlow::unitOperator();
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

void TestFlow::unitCopyConstructor() {
    cout << "Copy Constructor: ";
    System *s1 = new SystemImpl("s1", 0);
    System *s2 = new SystemImpl("s2", 0);
    FlowLog *log = new FlowLog("log");
    log->setSource(s1);
    log->setTarget(s2);
    FlowLog *newLog = new FlowLog((*log));

    assert(log->getName() == newLog->getName());
    assert(log->getSource() == newLog->getSource());
    assert(log->getTarget() == newLog->getTarget());

    FlowExp *exp = new FlowExp("exp", 50);
    exp->setSource(s1);
    exp->setTarget(s2);
    FlowExp *newExp = new FlowExp((*exp));

    assert(exp->getName() == newExp->getName());
    assert(exp->getSource() == newExp->getSource());
    assert(exp->getTarget() == newExp->getTarget());
    assert(exp->getTax() == newExp->getTax());
    cout << "OK" << endl;
}

void TestFlow::unitOperator() {
    cout << "operator=: ";
    System *s1 = new SystemImpl("s1", 0);
    System *s2 = new SystemImpl("s2", 0);
    FlowLog *log = new FlowLog("log");
    log->setSource(s1);
    log->setTarget(s2);
    FlowLog *newLog = new FlowLog("newLog");
    (*newLog) = (*log);

    assert(newLog != log);
    assert(log->getName() == newLog->getName());
    assert(log->getSource() == newLog->getSource());
    assert(log->getTarget() == newLog->getTarget());

    FlowExp *exp = new FlowExp("exp", 50);
    exp->setSource(s1);
    exp->setTarget(s2);
    FlowExp *newExp = new FlowExp("newExp", 25);
    (*newExp) = (*exp);

    assert(newExp != exp);
    assert(exp->getName() == newExp->getName());
    assert(exp->getSource() == newExp->getSource());
    assert(exp->getTarget() == newExp->getTarget());
    assert(fabs(exp->getTax() - newExp->getTax()) < 0.0001);

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

    cout << "OK" << endl;
}

void TestFlow::unitGetSource() {
    cout << "getSource: ";
    Flow *log = new FlowLog("log");
    Flow *exp = new FlowExp("exp", 0.01);

    assert(log->getSource() == nullptr);
    assert(exp->getSource() == nullptr);

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

    cout << "OK" << endl;
}

void TestFlow::unitGetTarget() {
    cout << "getTarget: ";
    Flow *log = new FlowLog("log");
    Flow *exp = new FlowExp("exp", 0.01);

    assert(log->getTarget() == nullptr);
    assert(exp->getTarget() == nullptr);

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

    cout << "OK" << endl;
}

void TestFlow::unitGetName() {
    cout << "getName: ";
    Flow *log = new FlowLog("log");
    Flow *exp = new FlowExp("exp", 0.01);

    assert(log->getName() == "log");
    assert(exp->getName() == "exp");

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

    cout << "OK" << endl;
}
