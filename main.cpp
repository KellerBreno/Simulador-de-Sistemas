#include <iostream>
#include <cassert>
#include "FlowExp.h"
#include "ModelImpl.h"
#include "SystemImpl.h"
#include "FlowLog.h"
#include "test/TestSystem.h"

// Modelo "exponencial"
void testVensim1() {
    cout << "Teste Vensim 1: ";

    System *p1 = new SystemImpl("pop1", 100);
    System *p2 = new SystemImpl("pop2", 0);

    Flow *exp = new FlowExp("exp", 0.01);
    exp->setSource(p1);
    exp->setTarget(p2);

    Model *m = new ModelImpl("exponencial");
    m->add(p1);
    m->add(p2);
    m->add(exp);

    m->simulate(1, 100);

    assert(p1->getValue() - 36.6032 < 0.0001);
    assert(p2->getValue() - 63.3968 < 0.0001);

    delete m;

    cout << "OK" << endl;
}

// Modelo "logistico"
void testVensim2() {
    cout << "Teste Vensim 2: ";

    System *p1 = new SystemImpl("pop1", 100);
    System *p2 = new SystemImpl("pop2", 10);

    Flow *log = new FlowLog("log");
    log->setSource(p1);
    log->setTarget(p2);

    Model *m = new ModelImpl("logistico");
    m->add(p1);
    m->add(p2);
    m->add(log);

    m->simulate(1, 100);

    assert(p1->getValue() - 88.2167 < 0.0001);
    assert(p2->getValue() - 21.7834 < 0.0001);

    delete m;

    cout << "OK" << endl;
}

// Sistema "complexo"
void testVensim3() {
    cout << "Teste Vensim 3: ";

    System *q1 = new SystemImpl("Q1", 100);
    System *q2 = new SystemImpl("Q2", 0);
    System *q3 = new SystemImpl("Q3", 100);
    System *q4 = new SystemImpl("Q4", 0);
    System *q5 = new SystemImpl("Q5", 0);

    Flow *f = new FlowExp("f", 0.01);
    f->setSource(q1);
    f->setTarget(q2);

    Flow *g = new FlowExp("g", 0.01);
    g->setSource(q1);
    g->setTarget(q3);

    Flow *u = new FlowExp("u", 0.01);
    u->setSource(q3);
    u->setTarget(q4);

    Flow *v = new FlowExp("v", 0.01);
    v->setSource(q4);
    v->setTarget(q1);

    Flow *r = new FlowExp("r", 0.01);
    r->setSource(q2);
    r->setTarget(q5);

    Flow *t = new FlowExp("t", 0.01);
    t->setSource(q2);
    t->setTarget(q3);

    Model *m = new ModelImpl("complexo");
    m->add(q1);
    m->add(q2);
    m->add(q3);
    m->add(q4);
    m->add(q5);
    m->add(f);
    m->add(g);
    m->add(u);
    m->add(v);
    m->add(r);
    m->add(t);

    m->simulate(1, 100);

    assert(q1->getValue() - 31.8513 < 0.0001);
    assert(q2->getValue() - 18.4003 < 0.0001);
    assert(q3->getValue() - 77.1143 < 0.0001);
    assert(q4->getValue() - 56.1728 < 0.0001);
    assert(q5->getValue() - 16.4612 < 0.0001);

    delete m;

    cout << "OK" << endl;
}

int main() {
    testVensim1();

    testVensim2();

    testVensim3();

    TestSystem::run();

    return 0;
}