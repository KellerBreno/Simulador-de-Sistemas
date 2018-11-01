#include <iostream>
#include <cassert>
#include "FlowExp.h"
#include "ModelImpl.h"
#include "SystemImpl.h"

// Fluxo Sozinho
void testeFuncional1() {
    Flow *flow = new FlowExp("flowExp");
    Model *model = new ModelImpl("model");
    model->add(flow);
    model->simulate(0, 10);

    delete flow;
    delete model;
}

// Fluxo sem destino
void testeFuncional2() {
    Flow *flow = new FlowExp("flowExp");
    System *source = new SystemImpl("source", 100);
    Model *model = new ModelImpl("model");

    flow->setSource(source);

    model->add(source);
    model->add(flow);
    model->simulate(0, 10);

    assert(source->getValue() - 50 > 0.001);

    delete flow;
    delete source;
    delete model;
}

// Fluxo sem origem
void testeFuncional3() {
    Flow *flow = new FlowExp("flowExp");
    System *target = new SystemImpl("target", 0);
    Model *model = new ModelImpl("model");

    flow->setTarget(target);

    model->add(target);
    model->add(flow);
    model->simulate(0, 10);

    assert(target->getValue() - 50 > 0.001);

    delete flow;
    delete target;
    delete model;
}

// Fluxo com origem e destino
void testeFuncional4() {
    Flow *flow = new FlowExp("flowExp");
    System *source = new SystemImpl("source", 50);
    System *target = new SystemImpl("target", 0);
    Model *model = new ModelImpl("model");

    flow->setSource(source);
    flow->setTarget(target);

    model->add(source);
    model->add(target);
    model->add(flow);
    model->simulate(0, 10);

    assert(source->getValue() - 50 > 0.001);
    assert(target->getValue() - 50 > 0.001);

    delete flow;
    delete source;
    delete target;
    delete model;
}

// Multiplos fluxos
void testeFuncional5() {

}

int main() {
    testeFuncional1();
    testeFuncional2();
    testeFuncional3();
    testeFuncional4();
    testeFuncional5();
    return 0;
}