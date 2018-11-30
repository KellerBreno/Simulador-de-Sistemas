/*!
* \file TestFlow.cpp
* Arquivo contendo a Implementação da Classe de testes de Fluxo
*
* \author Breno Keller
* \since 8/11/18
*/

#include <iostream>
#include <cassert>
#include <cmath>
#include "TestFlow.h"
#include "../src/Flow.h"
#include "../src/FlowImpl.h"
#include "../src/SystemHandle.h"

/*!
 * \brief Fluxo Exponencial para testes
 */
FLOW(FlowExp, 0.01 * source)

/*!
 * \brief Fluxo Logístico para testes
 */
FLOW(FlowLog, 0.01 * target * (1 - (target / 70)))

void TestFlow::run() {
    cout << "============= Testes Unitários Flow =============" << endl;
    TestFlow::unitConstructor();
    TestFlow::unitEqualDifferent();
    TestFlow::unitCopyConstructor();
    TestFlow::unitClone();
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

    System *source = new SystemHandle("s1", 0);
    System *target = new SystemHandle("s2", 0);

    Flow *log = new FlowLog("log");
    assert(log->getName() == "log");
    assert(log->getSource() == nullptr);
    assert(log->getTarget() == nullptr);

    Flow *otherLog = new FlowLog("");
    assert(otherLog->getName().empty());
    assert(otherLog->getSource() == nullptr);
    assert(otherLog->getTarget() == nullptr);

    Flow *anotherLog = new FlowLog("anotherLog", source, target);
    assert(anotherLog->getName() == "anotherLog");
    assert(anotherLog->getSource() == source);
    assert(anotherLog->getTarget() == target);

    Flow *anotherOtherLog = new FlowLog("", nullptr, nullptr);
    assert(anotherOtherLog->getName().empty());
    assert(anotherOtherLog->getSource() == nullptr);
    assert(anotherOtherLog->getTarget() == nullptr);

    Flow *exp = new FlowExp("exp");
    assert(exp->getName() == "exp");
    assert(exp->getSource() == nullptr);
    assert(exp->getTarget() == nullptr);

    Flow *otherExp = new FlowExp("");
    assert(otherExp->getName().empty());
    assert(otherExp->getSource() == nullptr);
    assert(otherExp->getTarget() == nullptr);

    Flow *anotherExp = new FlowExp("anotherExp", source, target);
    assert(anotherExp->getName() == "anotherExp");
    assert(anotherExp->getSource() == source);
    assert(anotherExp->getTarget() == target);

    Flow *anotherOtherExp = new FlowExp("", nullptr, nullptr);
    assert(anotherOtherExp->getName().empty());
    assert(anotherOtherExp->getSource() == nullptr);
    assert(anotherOtherExp->getTarget() == nullptr);

    delete (FlowLog *) log;
    delete (FlowLog *) otherLog;
    delete (FlowLog *) anotherLog;
    delete (FlowLog *) anotherOtherLog;
    delete (FlowExp *) exp;
    delete (FlowExp *) otherExp;
    delete (FlowExp *) anotherExp;
    delete (FlowExp *) anotherOtherExp;
    delete (SystemHandle *) source;
    delete (SystemHandle *) target;

    cout << "OK" << endl;
}

void TestFlow::unitCopyConstructor() {
    cout << "Copy Constructor: ";

    System *s1 = new SystemHandle("s1", 0);
    System *s2 = new SystemHandle("s2", 0);

    Flow *log = new FlowLog("log");
    log->setSource(s1);
    log->setTarget(s2);
    Flow *newLog = new FlowLog((*log));

    assert(newLog != log);
    assert(log->getName() == newLog->getName());
    assert(log->getSource() == newLog->getSource());
    assert(log->getTarget() == newLog->getTarget());

    Flow *exp = new FlowExp("exp");
    exp->setSource(s1);
    exp->setTarget(s2);
    Flow *newExp = new FlowExp((*exp));

    assert(newExp != exp);
    assert(exp->getName() == newExp->getName());
    assert(exp->getSource() == newExp->getSource());
    assert(exp->getTarget() == newExp->getTarget());

    delete (SystemHandle *) s1;
    delete (SystemHandle *) s2;
    delete (FlowLog *) log;
    delete (FlowLog *) newLog;
    delete (FlowExp *) exp;
    delete (FlowExp *) newExp;

    cout << "OK" << endl;
}

void TestFlow::unitOperator() {
    cout << "operator=: ";

    System *s1 = new SystemHandle("s1", 0);
    System *s2 = new SystemHandle("s2", 0);

    Flow *log = new FlowLog("log");
    log->setSource(s1);
    log->setTarget(s2);
    Flow *newLog = new FlowLog("newLog");
    (*newLog) = (*log);

    assert(newLog != log);
    assert(log->getName() == newLog->getName());
    assert(log->getSource() == newLog->getSource());
    assert(log->getTarget() == newLog->getTarget());

    Flow *exp = new FlowExp("exp");
    exp->setSource(s1);
    exp->setTarget(s2);
    Flow *newExp = new FlowExp("newExp");
    (*newExp) = (*exp);

    assert(newExp != exp);
    assert(exp->getName() == newExp->getName());
    assert(exp->getSource() == newExp->getSource());
    assert(exp->getTarget() == newExp->getTarget());

    delete (SystemHandle *) s1;
    delete (SystemHandle *) s2;
    delete (FlowLog *) log;
    delete (FlowLog *) newLog;
    delete (FlowExp *) exp;
    delete (FlowExp *) newExp;

    cout << "OK" << endl;
}

void TestFlow::unitExecute() {
    cout << "Execute: ";

    System *s1 = new SystemHandle("s1", 50);
    System *s2 = new SystemHandle("s2", 50);

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

    Flow *exp = new FlowExp("exp");
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

    delete (SystemHandle *) s1;
    delete (SystemHandle *) s2;
    delete (FlowLog *) log;
    delete (FlowExp *) exp;

    cout << "OK" << endl;
}

void TestFlow::unitGetSource() {
    cout << "getSource: ";

    Flow *log = new FlowLog("log");
    assert(log->getSource() == nullptr);

    Flow *exp = new FlowExp("exp");
    assert(exp->getSource() == nullptr);

    System *s1 = new SystemHandle("s1", 0);
    Flow *anotherLog = new FlowLog("log", s1, nullptr);
    assert(anotherLog->getSource() == s1);

    System *s2 = new SystemHandle("s2", 0);
    Flow *anotherExp = new FlowExp("exp", s2, nullptr);
    assert(anotherExp->getSource() == s2);

    delete (FlowLog *) log;
    delete (FlowExp *) exp;
    delete (FlowLog *) anotherLog;
    delete (FlowExp *) anotherExp;
    delete (SystemHandle *) s1;
    delete (SystemHandle *) s2;

    cout << "OK" << endl;
}

void TestFlow::unitSetSource() {
    cout << "setSource: ";

    System *s1 = new SystemHandle("s1", 50);
    System *s2 = new SystemHandle("s2", 0);
    System *s3 = new SystemHandle("s3", 25);

    Flow *log = new FlowLog("log");
    assert(log->getSource() == nullptr);

    log->setSource(s1);
    assert(log->getSource() == s1);

    log->setSource(s2);
    assert(log->getSource() != s1);
    assert(log->getSource() == s2);

    Flow *otherLog = new FlowLog("otherLog", s3, nullptr);
    assert(otherLog->getSource() == s3);

    otherLog->setSource(s2);
    assert(otherLog->getSource() != s3);
    assert(otherLog->getSource() == s2);

    Flow *exp = new FlowExp("exp");
    assert(exp->getSource() == nullptr);

    exp->setSource(s1);
    assert(exp->getSource() == s1);

    exp->setSource(s2);
    assert(exp->getSource() != s1);
    assert(exp->getSource() == s2);

    Flow *otherExp = new FlowExp("otherExp", s3, nullptr);
    assert(otherExp->getSource() == s3);

    otherExp->setSource(s2);
    assert(otherExp->getSource() != s3);
    assert(otherExp->getSource() == s2);

    delete (SystemHandle *) s1;
    delete (SystemHandle *) s2;
    delete (SystemHandle *) s3;
    delete (FlowLog *) log;
    delete (FlowLog *) otherLog;
    delete (FlowExp *) exp;
    delete (FlowExp *) otherExp;

    cout << "OK" << endl;
}

void TestFlow::unitGetTarget() {
    cout << "getTarget: ";

    Flow *log = new FlowLog("log");
    assert(log->getTarget() == nullptr);

    Flow *exp = new FlowExp("exp");
    assert(exp->getTarget() == nullptr);

    System *s1 = new SystemHandle("s1", 0);
    Flow *anotherLog = new FlowLog("log", nullptr, s1);
    assert(anotherLog->getTarget() == s1);

    System *s2 = new SystemHandle("s2", 0);
    Flow *anotherExp = new FlowExp("exp", nullptr, s2);
    assert(anotherExp->getTarget() == s2);

    delete (FlowLog *) log;
    delete (FlowLog *) anotherLog;
    delete (FlowExp *) exp;
    delete (FlowExp *) anotherExp;
    delete (SystemHandle *) s1;
    delete (SystemHandle *) s2;

    cout << "OK" << endl;
}

void TestFlow::unitSetTarget() {
    cout << "setTarget: ";

    System *s1 = new SystemHandle("s1", 50);
    System *s2 = new SystemHandle("s2", 0);
    System *s3 = new SystemHandle("s2", 25);

    Flow *log = new FlowLog("log");
    assert(log->getTarget() == nullptr);

    log->setTarget(s1);
    assert(log->getTarget() == s1);

    log->setTarget(s2);
    assert(log->getTarget() != s1);
    assert(log->getTarget() == s2);

    Flow *otherLog = new FlowLog("otherLog", nullptr, s3);
    assert(otherLog->getTarget() == s3);

    otherLog->setTarget(s2);
    assert(otherLog->getTarget() != s3);
    assert(otherLog->getTarget() == s2);

    Flow *exp = new FlowExp("exp");
    assert(exp->getTarget() == nullptr);

    exp->setTarget(s1);
    assert(exp->getTarget() == s1);

    exp->setTarget(s2);
    assert(exp->getTarget() != s1);
    assert(exp->getTarget() == s2);

    Flow *otherExp = new FlowExp("otherExp", nullptr, s3);
    assert(otherExp->getTarget() == s3);

    otherExp->setTarget(s2);
    assert(otherExp->getTarget() != s3);
    assert(otherExp->getTarget() == s2);

    delete (SystemHandle *) s1;
    delete (SystemHandle *) s2;
    delete (SystemHandle *) s3;
    delete (FlowLog *) log;
    delete (FlowLog *) otherLog;
    delete (FlowExp *) exp;
    delete (FlowExp *) otherExp;

    cout << "OK" << endl;
}

void TestFlow::unitGetName() {
    cout << "getName: ";

    Flow *log = new FlowLog("log");
    assert(log->getName() == "log");

    Flow *nLog = new FlowLog("");
    assert(nLog->getName().empty());

    Flow *exp = new FlowExp("exp");
    assert(exp->getName() == "exp");

    Flow *nExp = new FlowExp("");
    assert(nExp->getName().empty());

    delete (FlowLog *) log;
    delete (FlowLog *) nLog;
    delete (FlowExp *) exp;
    delete (FlowExp *) nExp;

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

    Flow *exp = new FlowExp("exp");
    assert(exp->getName() == "exp");

    exp->setName("expnew");
    assert(exp->getName() == "expnew");

    exp->setName("");
    assert(exp->getName().empty());

    delete (FlowLog *) log;
    delete (FlowExp *) exp;

    cout << "OK" << endl;
}

void TestFlow::unitEqualDifferent() {
    cout << "operator==: ";

    Flow *f1 = new FlowLog("l1");
    Flow *f2 = new FlowLog("l2");
    assert((*f1) != (*f2));

    (*f1) = (*f2);
    assert((*f1) == (*f2));

    Flow *f3 = new FlowExp("l3");
    Flow *f4 = new FlowExp("l4");
    assert((*f3) != (*f4));

    (*f3) = (*f4);
    assert((*f3) == (*f4));

    delete (FlowLog *) f1;
    delete (FlowLog *) f2;
    delete (FlowExp *) f3;
    delete (FlowExp *) f4;

    cout << "OK" << endl;
}

void TestFlow::unitClone() {
    cout << "clone: ";

    System *s1 = new SystemHandle("s1", 0);
    System *s2 = new SystemHandle("s2", 0);

    Flow *log = new FlowLog("log");
    log->setSource(s1);
    log->setTarget(s2);
    Flow *newLog = log->clone();

    assert(newLog != log);
    assert(log->getName() == newLog->getName());
    assert(log->getSource() == newLog->getSource());
    assert(log->getTarget() == newLog->getTarget());

    Flow *exp = new FlowExp("exp");
    exp->setSource(s1);
    exp->setTarget(s2);
    Flow *newExp = exp->clone();

    assert(newExp != exp);
    assert(exp->getName() == newExp->getName());
    assert(exp->getSource() == newExp->getSource());
    assert(exp->getTarget() == newExp->getTarget());

    delete (SystemHandle *) s1;
    delete (SystemHandle *) s2;
    delete (FlowLog *) log;
    delete (FlowLog *) newLog;
    delete (FlowExp *) exp;
    delete (FlowExp *) newExp;

    cout << "OK" << endl;
}