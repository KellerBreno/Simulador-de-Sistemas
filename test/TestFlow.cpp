//
// Created by brenokeller on 11/8/18.
//

#include <iostream>
#include <cassert>
#include <cmath>
#include "TestFlow.h"
#include "../src/Flow.h"
#include "../src/FlowExp.h"
#include "../src/FlowLog.h"
#include "../src/SystemImpl.h"

void TestFlow::run() {
    cout << "============= Testes Unitários Flow =============" << endl;
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
    assert(log->getName() == "log");
    assert(log->getSource() == nullptr);
    assert(log->getTarget() == nullptr);

    Flow *otherLog = new FlowLog("");
    assert(otherLog->getName().empty());
    assert(otherLog->getSource() == nullptr);
    assert(otherLog->getTarget() == nullptr);

    Flow *exp = new FlowExp("exp", 0.01);
    assert(exp->getName() == "exp");
    assert(exp->getSource() == nullptr);
    assert(exp->getTarget() == nullptr);

    Flow *otherExp = new FlowExp("", (1 / 3));
    assert(otherExp->getName().empty());
    assert(otherExp->getSource() == nullptr);
    assert(otherExp->getTarget() == nullptr);

    auto aux = dynamic_cast<FlowExp *>(exp);
    assert(fabs(aux->getTax() - 0.01) < 0.0001);

    auto otherAux = dynamic_cast<FlowExp *>(otherExp);
    assert(fabs(otherAux->getTax() - (1 / 3)) < 0.0001);

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

    assert(newLog != log);
    assert(log->getName() == newLog->getName());
    assert(log->getSource() == newLog->getSource());
    assert(log->getTarget() == newLog->getTarget());

    FlowExp *exp = new FlowExp("exp", 50);
    exp->setSource(s1);
    exp->setTarget(s2);
    FlowExp *newExp = new FlowExp((*exp));

    assert(newExp != exp);
    assert(exp->getName() == newExp->getName());
    assert(exp->getSource() == newExp->getSource());
    assert(exp->getTarget() == newExp->getTarget());
    assert(fabs(exp->getTax() - newExp->getTax()) < 0.0001);

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
    System *s2 = new SystemImpl("s2", 50);

    Flow *log = new FlowLog("log");
    assert(fabs(log->execute()) < 0.0001);

    log->setSource(s1);
    log->setTarget(nullptr);
    assert(fabs(log->execute()) < 0.0001);

    log->setSource(nullptr);
    log->setTarget(s2);
    assert(fabs(log->execute() - 0.1429) < 0.0001);

    log->setSource(s1);
    log->setTarget(s2);
    assert(fabs(log->execute() - 0.1429) < 0.0001);

    Flow *exp = new FlowExp("exp", 0.01);
    assert(fabs(exp->execute()) < 0.0001);

    exp->setSource(s1);
    exp->setTarget(nullptr);
    assert(fabs(exp->execute() - 0.5) < 0.0001);

    exp->setSource(nullptr);
    exp->setTarget(s2);
    assert(fabs(exp->execute()) < 0.0001);

    exp->setSource(s1);
    exp->setTarget(s2);
    assert(fabs(exp->execute() - 0.5) < 0.0001);

    cout << "OK" << endl;
}

void TestFlow::unitGetSource() {
    cout << "getSource: ";

    Flow *log = new FlowLog("log");
    assert(log->getSource() == nullptr);

    Flow *exp = new FlowExp("exp", 0.01);
    assert(exp->getSource() == nullptr);

    cout << "OK" << endl;
}

void TestFlow::unitSetSource() {
    cout << "setSource: ";

    System *s1 = new SystemImpl("s1", 50);
    System *s2 = new SystemImpl("s2", 0);

    Flow *log = new FlowLog("log");
    assert(log->getSource() == nullptr);

    log->setSource(s1);
    assert(log->getSource() == s1);

    log->setSource(s2);
    assert(log->getSource() != s1);
    assert(log->getSource() == s2);

    Flow *exp = new FlowExp("exp", 0.01);
    assert(exp->getSource() == nullptr);

    exp->setSource(s1);
    assert(exp->getSource() == s1);

    exp->setSource(s2);
    assert(exp->getSource() != s1);
    assert(exp->getSource() == s2);

    cout << "OK" << endl;
}

void TestFlow::unitGetTarget() {
    cout << "getTarget: ";

    Flow *log = new FlowLog("log");
    assert(log->getTarget() == nullptr);

    Flow *exp = new FlowExp("exp", 0.01);
    assert(exp->getTarget() == nullptr);

    cout << "OK" << endl;
}

void TestFlow::unitSetTarget() {
    cout << "setTarget: ";

    System *s1 = new SystemImpl("s1", 50);
    System *s2 = new SystemImpl("s2", 0);

    Flow *log = new FlowLog("log");
    assert(log->getTarget() == nullptr);

    log->setTarget(s1);
    assert(log->getTarget() == s1);

    log->setTarget(s2);
    assert(log->getTarget() != s1);
    assert(log->getTarget() == s2);

    Flow *exp = new FlowExp("exp", 0.01);
    assert(exp->getTarget() == nullptr);

    exp->setTarget(s1);
    assert(exp->getTarget() == s1);

    exp->setTarget(s2);
    assert(exp->getTarget() != s1);
    assert(exp->getTarget() == s2);

    cout << "OK" << endl;
}

void TestFlow::unitGetName() {
    cout << "getName: ";

    Flow *log = new FlowLog("log");
    assert(log->getName() == "log");

    Flow *nLog = new FlowLog("");
    assert(nLog->getName().empty());

    Flow *exp = new FlowExp("exp", 0.01);
    assert(exp->getName() == "exp");

    Flow *nExp = new FlowExp("", 0.01);
    assert(nExp->getName().empty());

    cout << "OK" << endl;
}

void TestFlow::unitSetName() {
    cout << "setName: ";

    Flow *log = new FlowLog("log");
    assert(log->getName() == "log");
    log->setName("lognew");
    assert(log->getName() == "lognew");
    log->setName("");
    assert(log->getName().empty());

    Flow *exp = new FlowExp("exp", 0.01);
    assert(exp->getName() == "exp");
    exp->setName("expnew");
    assert(exp->getName() == "expnew");
    exp->setName("");
    assert(exp->getName().empty());

    cout << "OK" << endl;
}
