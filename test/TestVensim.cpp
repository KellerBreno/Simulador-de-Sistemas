//
// Created by brenokeller on 11/6/18.
//

#include <iostream>
#include <cassert>
#include <cmath>
#include "TestVensim.h"
#include "../src/Model.h"

FLOW(FlowExp, 0.01 * source)

FLOW(FlowLog, 0.01 * target * (1 - (target / 70)))

void TestVensim::run() {
    cout << "================= Testes Vensim =================" << endl;
    TestVensim::modelExp();
    TestVensim::modelLog();
    TestVensim::modelWithLoop();
    TestVensim::modelCopy();
    TestVensim::modelAtrib();
    cout << "=================================================" << endl;
}

void TestVensim::modelExp() {
    cout << "Teste Vensim 1: ";

    Model *m = Model::createModel("exponencial");
    System *p1 = m->createSystem("pop1", 100);
    System *p2 = m->createSystem("pop2");
    Flow *exp = m->createFlow<FlowExp>("exp");
    exp->setSource(p1);
    exp->setTarget(p2);

    m->simulate(1, 100);

    assert(fabs(p1->getValue() - 36.6032) < 0.0001);
    assert(fabs(p2->getValue() - 63.3968) < 0.0001);

    Model::deleteModel("exponencial");

    cout << "OK" << endl;
}

void TestVensim::modelLog() {
    cout << "Teste Vensim 2: ";

    Model *m = Model::createModel("logistico");
    System *p1 = m->createSystem("pop1", 100);
    System *p2 = m->createSystem("pop2", 10);

    Flow *log = m->createFlow<FlowLog>("log");
    log->setSource(p1);
    log->setTarget(p2);

    m->simulate(1, 100);

    assert(fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(fabs(p2->getValue() - 21.7834) < 0.0001);

    Model::deleteModel("logistico");

    cout << "OK" << endl;
}

void TestVensim::modelWithLoop() {
    cout << "Teste Vensim 3: ";

    Model *m = Model::createModel("complexo");
    System *q1 = m->createSystem("Q1", 100);
    System *q2 = m->createSystem("Q2");
    System *q3 = m->createSystem("Q3", 100);
    System *q4 = m->createSystem("Q4");
    System *q5 = m->createSystem("Q5");

    Flow *f = m->createFlow<FlowExp>("f");
    f->setSource(q1);
    f->setTarget(q2);

    Flow *g = m->createFlow<FlowExp>("g");
    g->setSource(q1);
    g->setTarget(q3);

    Flow *u = m->createFlow<FlowExp>("u");
    u->setSource(q3);
    u->setTarget(q4);

    Flow *v = m->createFlow<FlowExp>("v");
    v->setSource(q4);
    v->setTarget(q1);

    Flow *r = m->createFlow<FlowExp>("r");
    r->setSource(q2);
    r->setTarget(q5);

    Flow *t = m->createFlow<FlowExp>("t");
    t->setSource(q2);
    t->setTarget(q3);

    m->simulate(1, 100);

    assert(fabs(q1->getValue() - 31.8513) < 0.0001);
    assert(fabs(q2->getValue() - 18.4003) < 0.0001);
    assert(fabs(q3->getValue() - 77.1143) < 0.0001);
    assert(fabs(q4->getValue() - 56.1728) < 0.0001);
    assert(fabs(q5->getValue() - 16.4612) < 0.0001);

    Model::deleteModel("complexo");

    cout << "OK" << endl;
}

void TestVensim::modelCopy() {
    cout << "Teste Construtor de Copia: ";

    Model *m = Model::createModel("complexo");

    System *q1 = m->createSystem("Q1", 100);
    System *q2 = m->createSystem("Q2", 0);
    System *q3 = m->createSystem("Q3", 100);
    System *q4 = m->createSystem("Q4", 0);
    System *q5 = m->createSystem("Q5", 0);

    Flow *f = m->createFlow<FlowExp>("f");
    f->setSource(q1);
    f->setTarget(q2);

    Flow *g = m->createFlow<FlowExp>("g");
    g->setSource(q1);
    g->setTarget(q3);

    Flow *u = m->createFlow<FlowExp>("u");
    u->setSource(q3);
    u->setTarget(q4);

    Flow *v = m->createFlow<FlowExp>("v");
    v->setSource(q4);
    v->setTarget(q1);

    Flow *r = m->createFlow<FlowExp>("r");
    r->setSource(q2);
    r->setTarget(q5);

    Flow *t = m->createFlow<FlowExp>("t");
    t->setSource(q2);
    t->setTarget(q3);

    Model *newModel = Model::createModel(m);
    newModel->setName("copy");

    Model::deleteModel("complexo");

    newModel->simulate(1, 100);

    System *nq1 = newModel->getSystem("Q1");
    System *nq2 = newModel->getSystem("Q2");
    System *nq3 = newModel->getSystem("Q3");
    System *nq4 = newModel->getSystem("Q4");
    System *nq5 = newModel->getSystem("Q5");

    assert(fabs(nq1->getValue() - 31.8513) < 0.0001);
    assert(fabs(nq2->getValue() - 18.4003) < 0.0001);
    assert(fabs(nq3->getValue() - 77.1143) < 0.0001);
    assert(fabs(nq4->getValue() - 56.1728) < 0.0001);
    assert(fabs(nq5->getValue() - 16.4612) < 0.0001);

    Model::deleteModel("copy");

    cout << "OK" << endl;
}

void TestVensim::modelAtrib() {
    cout << "Teste Atribuição: ";

    Model *model = Model::createModel("complexo");

    System *q1 = model->createSystem("Q1", 100);
    System *q2 = model->createSystem("Q2", 0);
    System *q3 = model->createSystem("Q3", 100);
    System *q4 = model->createSystem("Q4", 0);
    System *q5 = model->createSystem("Q5", 0);
    Flow *f = model->createFlow<FlowExp>("f", q1, q2);
    Flow *g = model->createFlow<FlowExp>("g", q1, q3);
    Flow *u = model->createFlow<FlowExp>("u", q3, q4);
    Flow *v = model->createFlow<FlowExp>("v", q4, q1);
    Flow *r = model->createFlow<FlowExp>("r", q2, q5);
    Flow *t = model->createFlow<FlowExp>("t", q2, q3);

    Model *newModel = Model::createModel("model");
    (*newModel) = (*model);
    newModel->setName("copy");

    Model::deleteModel("complexo");

    newModel->simulate(1, 100);

    System *nq1 = newModel->getSystem("Q1");
    System *nq2 = newModel->getSystem("Q2");
    System *nq3 = newModel->getSystem("Q3");
    System *nq4 = newModel->getSystem("Q4");
    System *nq5 = newModel->getSystem("Q5");

    assert(fabs(nq1->getValue() - 31.8513) < 0.0001);
    assert(fabs(nq2->getValue() - 18.4003) < 0.0001);
    assert(fabs(nq3->getValue() - 77.1143) < 0.0001);
    assert(fabs(nq4->getValue() - 56.1728) < 0.0001);
    assert(fabs(nq5->getValue() - 16.4612) < 0.0001);

    Model::deleteModel("copy");

    cout << "OK" << endl;
}
