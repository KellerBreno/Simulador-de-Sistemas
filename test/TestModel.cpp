/*!
* \file TestModel.cpp
* Arquivo contendo a Implementação da Classe de testes de Modelo
*
* \author Breno Keller
* \since 8/11/18
*/

#include <iostream>
#include <cassert>
#include <cmath>
#include "TestModel.h"
#include "../src/ModelImpl.h"
#include "../src/SystemHandle.h"

/*!
 * \brief Fluxo Exponencial para testes
 */
FLOW(FlowExp, 0.01 * source)

/*!
 * \brief Fluxo Logístico para testes
 */
FLOW(FlowLog, 0.01 * target * (1 - (target / 70)))

void TestModel::run() {
    cout << "============ Testes Unitários Model =============" << endl;
    TestModel::unitConstructor();
    TestModel::unitCreateModel();
    TestModel::unitCreateModelCopy();
    TestModel::unitDeleteModel();
    TestModel::unitEqualDifferent();
    TestModel::unitCopyConstructor();
    TestModel::unitOperator();
    TestModel::unitAdd();
    TestModel::unitCreateSystem();
    TestModel::unitCreateFlow();
    TestModel::unitDeleteSystem();
    TestModel::unitDeleteFlow();
    TestModel::unitGetFlow();
    TestModel::unitGetSystem();
    TestModel::unitGetName();
    TestModel::unitSetName();
    TestModel::unitSimulate();
    TestModel::unitReport();
    TestModel::unitFlowIterator();
    TestModel::unitSystemIterator();
    cout << "=================================================" << endl;
}

void TestModel::unitConstructor() {
    cout << "Constructor: ";

    Model *model = new ModelImpl("model");
    assert(model->getName() == "model");

    System *s = model->getSystem("s");
    assert(s == nullptr);
    Flow *f = model->getFlow("f");
    assert(f == nullptr);

    Model *newModel = new ModelImpl("");
    assert(newModel->getName().empty());

    System *ns = newModel->getSystem("s");
    assert(ns == nullptr);
    Flow *nf = newModel->getFlow("f");
    assert(nf == nullptr);

    delete (ModelImpl *) model;
    delete (ModelImpl *) newModel;

    cout << "OK" << endl;
}

void TestModel::unitCopyConstructor() {
    cout << "Copy Constructor: ";

    Model *model = Model::createModel("model");
    System *s1 = model->createSystem("s1", 0);
    System *s2 = model->createSystem("s2", 0);
    Flow *f1 = model->createFlow<FlowLog>("f1");
    Flow *f2 = model->createFlow<FlowExp>("f2");

    ModelImpl *cast = dynamic_cast<ModelImpl *>(model);
    Model *newModel = new ModelImpl((*cast));
    assert(newModel != model);

    System *s3 = newModel->getSystem("s1");
    assert(s3 != nullptr);
    assert((*s3) == (*s1));

    System *s4 = newModel->getSystem("s2");
    assert(s4 != nullptr);
    assert((*s4) == (*s2));

    Flow *f3 = newModel->getFlow("f1");
    assert(f3 != nullptr);
    assert((*f3) == (*f1));

    Flow *f4 = newModel->getFlow("f2");
    assert(f4 != nullptr);
    assert((*f4) == (*f2));

    assert(model->getName() == newModel->getName());

    Model::deleteModel("model");
    delete (ModelImpl *) newModel;

    cout << "OK" << endl;
}

void TestModel::unitOperator() {
    cout << "operator=: ";

    Model *model = Model::createModel("model");
    System *s1 = model->createSystem("s1", 0);
    System *s2 = model->createSystem("s2", 0);
    Flow *f1 = model->createFlow<FlowLog>("f1");
    Flow *f2 = model->createFlow<FlowExp>("f2");

    Model *newModel = Model::createModel("newModel");
    (*newModel) = (*model);
    assert(newModel != model);

    System *s3 = newModel->getSystem("s1");
    assert(s3 != nullptr);
    assert((*s3) == (*s1));
    assert(s3 != s1);

    System *s4 = newModel->getSystem("s2");
    assert(s4 != nullptr);
    assert((*s4) == (*s2));
    assert(s4 != s2);

    Flow *f3 = newModel->getFlow("f1");
    assert(f3 != nullptr);
    assert((*f3) == (*f1));
    assert(f3 != f1);

    Flow *f4 = newModel->getFlow("f2");
    assert(f4 != nullptr);
    assert((*f4) == (*f2));
    assert(f4 != f2);

    assert(model->getName() == newModel->getName());

    newModel->setName("newModel");

    Model::deleteModel("model");
    Model::deleteModel("newModel");

    cout << "OK" << endl;
}

void TestModel::unitSimulate() {
    cout << "simulate: ";

    Model *model = Model::createModel("teste");
    System *p1 = model->createSystem("p1", 50);
    System *p2 = model->createSystem("p2", 0);
    Flow *exp = model->createFlow<FlowExp>("exp", p1, p2);

    model->simulate(1, 10);

    assert(fabs(p1->getValue() - 45.2191) < 0.0001);
    assert(fabs(p2->getValue() - 4.7809) < 0.0001);

    Model *newModel = Model::createModel("outro teste");
    System *np1 = newModel->createSystem("p1", 50);
    System *np2 = newModel->createSystem("p2", 0);
    Flow *nExp = newModel->createFlow<FlowExp>("exp", np1, np2);

    newModel->simulate(1, 10, 1);

    assert(fabs(np1->getValue() - 45.2191) < 0.0001);
    assert(fabs(np2->getValue() - 4.7809) < 0.0001);

    assert(fabs(p1->getValue() - np1->getValue()) < 0.0001);
    assert(fabs(p2->getValue() - np2->getValue()) < 0.0001);

    Model *jumpModel = Model::createModel("teste jump");
    System *jp1 = jumpModel->createSystem("p1", 50);
    System *jp2 = jumpModel->createSystem("p2", 0);
    Flow *jExp = jumpModel->createFlow<FlowExp>("exp", jp1, jp2);

    jumpModel->simulate(1, 10, 2);

    assert(fabs(jp1->getValue() - 47.5495) < 0.0001);
    assert(fabs(jp2->getValue() - 2.4505) < 0.0001);

    Model::deleteModel("teste");
    Model::deleteModel("outro teste");
    Model::deleteModel("teste jump");

    cout << "OK" << endl;
}

void TestModel::unitAdd() {
    cout << "add: ";

    Model *model = Model::createModel("model");

    System *s1 = new SystemHandle("s1", 0);
    Flow *f1 = new FlowHandle<FlowLog>("f1");
    Flow *f2 = new FlowHandle<FlowExp>("f2");

    model->add(s1);
    model->add(f1);
    model->add(f2);

    System *s2 = model->getSystem("s1");
    assert(s2 != nullptr);
    assert(s2 == s1);

    int cont = 0;
    for (Model::systemIterator it = model->beginSystems(); it != model->endSystems(); ++it) {
        cont++;
    }
    assert(cont == 1);

    Flow *f3 = model->getFlow("f1");
    assert(f3 != nullptr);
    assert(f3 == f1);

    Flow *f4 = model->getFlow("f2");
    assert(f4 != nullptr);
    assert(f4 == f2);

    cont = 0;
    for (Model::flowIterator it = model->beginFlows(); it != model->endFlows(); ++it) {
        cont++;
    }
    assert(cont == 2);

    Model::deleteModel("model");

    cout << "OK" << endl;
}

void TestModel::unitGetFlow() {
    cout << "getFlow: ";

    Model *model = Model::createModel("modelo");

    Flow *f = model->getFlow("l");
    assert(f == nullptr);

    Flow *f1 = model->createFlow<FlowLog>("log");
    Flow *f2 = model->getFlow("log");
    assert(f2 != nullptr);
    assert(f1 == f2);

    Flow *f3 = model->createFlow<FlowExp>("exp");
    Flow *f4 = model->getFlow("exp");
    assert(f4 != nullptr);
    assert(f3 == f4);

    Model::deleteModel("modelo");

    cout << "OK" << endl;
}

void TestModel::unitGetSystem() {
    cout << "getSystem: ";

    Model *model = Model::createModel("modelo");

    System *s = model->getSystem("s");
    assert(s == nullptr);

    System *s1 = model->createSystem("s1", 0);
    System *s2 = model->getSystem("s1");
    assert(s2 != nullptr);
    assert(s1 == s2);

    Model::deleteModel("modelo");

    cout << "OK" << endl;
}

void TestModel::unitGetName() {
    cout << "getName: ";

    Model *model = Model::createModel("model");
    assert(model->getName() == "model");

    Model::deleteModel("model");

    cout << "OK" << endl;
}

void TestModel::unitSetName() {
    cout << "setName: ";

    Model *model = Model::createModel("model");
    assert(model->getName() == "model");

    model->setName("modelnew");
    assert(model->getName() == "modelnew");

    Model::deleteModel("modelnew");

    cout << "OK" << endl;
}

void TestModel::unitReport() {
    cout << "report: ";

    Model *model = Model::createModel("teste");

    System *p1 = model->createSystem("p1", 50);
    System *p2 = model->createSystem("p2", 0);

    Flow *exp = model->createFlow<FlowExp>("exp", p1, p2);

    model->simulate(1, 10);

    string expected = "===========================================================\n"
                      "Modelo: teste\n"
                      "----------------------- Sistemas --------------------------\n"
                      "Sistema: p1 - 45.2191\n"
                      "Sistema: p2 - 4.7809\n"
                      "------------------------ Fluxos ---------------------------\n"
                      "Fluxo: exp\n"
                      "===========================================================\n";
    string actual = model->report();
    assert(expected == actual);

    Model::deleteModel("teste");

    model = Model::createModel("vazio");
    expected = "===========================================================\n"
               "Modelo: vazio\n"
               "----------------------- Sistemas --------------------------\n"
               "------------------------ Fluxos ---------------------------\n"
               "===========================================================\n";
    actual = model->report();
    assert(expected == actual);

    Model::deleteModel("vazio");

    cout << "OK" << endl;
}

void TestModel::unitEqualDifferent() {
    cout << "operator==: ";

    Model *m1 = Model::createModel("model1");
    Model *m2 = Model::createModel("model2");
    assert((*m1) != (*m2));

    (*m2) = (*m1);
    assert((*m2) == (*m1));
    m2->setName("model2");

    Model::deleteModel("model1");
    Model::deleteModel("model2");

    Model *m3 = Model::createModel("model3");
    Model *m4 = Model::createModel("model4");

    System *s1 = m3->createSystem("s1", 0);
    System *s2 = m4->createSystem("s2", 0);
    assert((*m3) != (*m4));

    (*m4) = (*m3);
    assert((*m3) == (*m4));
    m4->setName("model4");

    Model::deleteModel("model3");
    Model::deleteModel("model4");

    cout << "OK" << endl;
}

void TestModel::unitDeleteSystem() {
    cout << "deleteSystem: ";

    Model *model = Model::createModel("model");

    model->deleteSystem("s");
    System *s = model->getSystem("s");
    assert(s == nullptr);

    System *s1 = model->createSystem("s1", 0);
    System *s2 = model->createSystem("s2", 0);

    model->deleteSystem("s1");
    System *s3 = model->getSystem("s1");
    assert(s3 != s1);
    assert(s3 == nullptr);

    Model::deleteModel("model");

    cout << "OK" << endl;
}

void TestModel::unitDeleteFlow() {
    cout << "deleteFlow: ";

    Model *model = Model::createModel("model");

    model->deleteFlow("f");
    Flow *f = model->getFlow("f");
    assert(f == nullptr);

    Flow *f1 = model->createFlow<FlowLog>("f1");
    Flow *f2 = model->createFlow<FlowLog>("f2");

    model->deleteFlow("f1");
    Flow *f3 = model->getFlow("f1");
    assert(f3 != f1);
    assert(f3 == nullptr);

    Model::deleteModel("model");

    cout << "OK" << endl;
}

void TestModel::unitCreateSystem() {
    cout << "createSystem: ";

    Model *m = Model::createModel("model");

    System *s1 = m->createSystem("s1");
    assert(s1->getName() == "s1");
    assert(fabs(s1->getValue()) < 0.0001);

    System *s2 = m->createSystem("s2", 100);
    assert(s2->getName() == "s2");
    assert(fabs(s2->getValue() - 100) < 0.0001);

    System *s3 = m->createSystem(s2);
    assert (s2 != s3);
    assert((*s2) == (*s3));

    Model::deleteModel("model");

    cout << "OK" << endl;
}

void TestModel::unitCreateFlow() {
    cout << "createFlow: ";

    Model *m = Model::createModel("model");

    System *s1 = m->createSystem("s1");
    System *s2 = m->createSystem("s2");

    Flow *f1 = m->createFlow<FlowLog>("f1");
    assert(f1->getName() == "f1");
    assert(f1->getSource() == nullptr);
    assert(f1->getTarget() == nullptr);

    Flow *f2 = m->createFlow<FlowLog>("f2", s1, s2);
    assert(f2->getName() == "f2");
    assert(f2->getSource() == s1);
    assert(f2->getTarget() == s2);

    Model::deleteModel("model");

    cout << "OK" << endl;
}

//TODO testes para factory acesso ao vector models_
void TestModel::unitCreateModel() {
    cout << "createModel: ";

    Model *m1 = Model::createModel("teste");
    assert(m1->getName() == "teste");

    Model *m2 = Model::createModel("");
    assert(m2 == nullptr);

    Model::deleteModel("teste");

    cout << "OK" << endl;
}

void TestModel::unitCreateModelCopy() {
    cout << "createModel Copy: ";

    Model *m1 = Model::createModel("teste");
    assert(m1->getName() == "teste");
    System *s1 = m1->createSystem("s1");
    System *s2 = m1->createSystem("s2");

    Model *m2 = Model::createModel(m1);
    m2->setName("copy");

    System *s3 = m2->getSystem("s1");
    assert(s3 != nullptr);
    assert((*s1) == (*s3));

    System *s4 = m2->getSystem("s2");
    assert(s4 != nullptr);
    assert((*s2) == (*s4));

    Model::deleteModel("teste");
    Model::deleteModel("copy");

    cout << "OK" << endl;
}

void TestModel::unitDeleteModel() {
    cout << "deleteModel: ";

    Model *m1 = Model::createModel("teste");

    Model::deleteModel("teste");

    cout << "OK" << endl;
}

void TestModel::unitFlowIterator() {
    cout << "flowIterator: ";

    Model *m = Model::createModel("model");
    System *s1 = m->createSystem("s1");
    System *s2 = m->createSystem("s2");
    Flow *f1 = m->createFlow<FlowLog>("f1", s1, nullptr);
    Flow *f2 = m->createFlow<FlowLog>("f2", nullptr, s2);
    Flow *f3 = m->createFlow<FlowLog>("f3", s1, s2);

    Model::flowIterator it = m->beginFlows();
    assert((*it)->getName() == f1->getName());
    assert((*it)->getSource() == f1->getSource());
    assert((*it)->getTarget() == f1->getTarget());

    int cont = 0;
    for (; it != m->endFlows(); ++it) {
        cont++;
    }

    assert(cont == 3);

    Model::deleteModel("model");

    cout << "OK" << endl;
}

void TestModel::unitSystemIterator() {
    cout << "systemIterator: ";

    Model *m = Model::createModel("model");
    System *s1 = m->createSystem("s1", 50);
    System *s2 = m->createSystem("s2");

    Model::systemIterator it = m->beginSystems();
    assert((*it)->getName() == s1->getName());
    assert((*it)->getValue() == s1->getValue());

    int cont = 0;
    for (; it != m->endSystems(); ++it) {
        cont++;
    }

    assert(cont == 2);

    Model::deleteModel("model");

    cout << "OK" << endl;
}