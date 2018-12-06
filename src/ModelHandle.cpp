/*!
* \file ModelHandle.h
* Arquivo contendo a Implementação da Classe ModelHandle
*
* \author Breno Keller
* \since 04/12/18
*/

#include "ModelHandle.h"
#include "SystemHandle.h"

vector<Model *> ModelHandle::models_;

Model *Model::createModel(string name) {
    return ModelHandle::createModel(name);
}

Model *Model::createModel(Model *model) {
    return ModelHandle::createModel(model);
}

bool Model::deleteModel(string name) {
    return ModelHandle::deleteModel(name);
}

Model *ModelHandle::createModel(string name) {
    if (name.empty()) {
        return nullptr;
    }
    Model *m = new ModelHandle(name);
    models_.push_back(m);
    return m;
}

Model *ModelHandle::createModel(Model *model) {
    Model *m = new ModelHandle(model->getName());

    if (model->beginSystems()) {
        do {
            System *s = model->getCurrentSystem();
            m->createSystem(s->getName(), s->getValue());
        } while (model->nextSystem());
    }

    if (model->beginFlows()) {
        do {
            Flow *copy = m->createFlow(model->getCurrentFlow());
            if (m->beginSystems()) {
                do {
                    System *s = m->getCurrentSystem();
                    if ((copy->getSource() != nullptr) && *(copy->getSource()) == *(s)) {
                        copy->setSource(s);
                    } else if ((copy->getTarget() != nullptr) && *(copy->getTarget()) == *(s)) {
                        copy->setTarget(s);
                    }
                } while (m->nextSystem());
            }
        } while (model->nextFlow());
    }
    models_.push_back(m);
    return m;
}

bool ModelHandle::deleteModel(string name) {
    for (auto it = models_.begin(); it != models_.end(); ++it) {
        ModelHandle *m = dynamic_cast<ModelHandle *>(*it);
        if (m->getName() == name) {
            models_.erase(it);
            delete m;
            return true;
        }
    }
    return false;
}

ModelHandle::ModelHandle(string name) : Handle() {
    pImpl_->setName(name);
}

ModelHandle::~ModelHandle() {

}

void ModelHandle::simulate(int initialTime, int endTime) {
    pImpl_->simulate(initialTime, endTime);
}

void ModelHandle::simulate(int initialTime, int endTime, int step) {
    pImpl_->simulate(initialTime, endTime, step);
}

Flow *ModelHandle::getFlow(string name) {
    return pImpl_->getFlow(name);
}

System *ModelHandle::getSystem(string name) {
    return pImpl_->getSystem(name);
}

bool ModelHandle::deleteFlow(string name) {
    return pImpl_->deleteFlow(name);
}

bool ModelHandle::deleteSystem(string name) {
    return pImpl_->deleteSystem(name);
}

string ModelHandle::getName() const {
    return pImpl_->getName();
}

void ModelHandle::setName(string name) {
    pImpl_->setName(name);
}

string ModelHandle::report() {
    return pImpl_->report();
}

System *ModelHandle::createSystem(string name) {
    return pImpl_->createSystem(name);
}

System *ModelHandle::createSystem(string name, double initValue) {
    return pImpl_->createSystem(name, initValue);
}

System *ModelHandle::createSystem(System *system) {
    return pImpl_->createSystem(system);
}

bool ModelHandle::operator==(const Model &rhs) {
    bool resp = this->getName() == rhs.getName();

    bool aux;

    if (this->beginSystems()) {
        do {
            aux = false;
            if (rhs.beginSystems()) {
                do {
                    if (*(this->getCurrentSystem()) == *(rhs.getCurrentSystem())) {
                        aux = true;
                        continue;
                    }
                } while (rhs.nextSystem());
            }
            if (!aux) {
                resp = false;
            }
        } while (this->nextSystem());
    }

    if (this->beginFlows()) {
        do {
            aux = false;
            if (rhs.beginFlows()) {
                do {
                    if (*(this->getCurrentFlow()) == *(rhs.getCurrentFlow())) {
                        aux = true;
                        continue;
                    }
                } while (rhs.nextFlow());
                if (!aux) {
                    resp = false;
                }
            }
        } while (this->nextFlow());
    }
    return resp;
}

bool ModelHandle::operator!=(const Model &rhs) {
    return !(operator==(rhs));
}

Model &ModelHandle::operator=(Model &rhs) {
    if (this->beginSystems()) {
        do {
            delete (SystemHandle *) this->getCurrentSystem();
        } while (this->nextSystem());
    }

    if (this->beginFlows()) {
        do {
            // TODO Slicing
            delete (Handle *) this->getCurrentFlow();
        } while (this->nextFlow());
    }

    this->clearFlows();

    this->clearSystems();

    if (rhs.beginSystems()) {
        do {
            this->createSystem(rhs.getCurrentSystem());
        } while (rhs.nextSystem());
    }

    if (rhs.beginFlows()) {
        do {
            Flow *copy = this->createFlow(rhs.getCurrentFlow());
            if (this->beginSystems()) {
                do {
                    System *system = this->getCurrentSystem();
                    if ((copy->getSource() != nullptr) && *(copy->getSource()) == (*system)) {
                        copy->setSource(system);
                    } else if ((copy->getTarget() != nullptr) && *(copy->getTarget()) == (*system)) {
                        copy->setTarget(system);
                    }
                } while (this->nextSystem());
            }
        } while (rhs.nextFlow());
    }

    this->setName(rhs.getName());

    return *this;
}

void ModelHandle::clearFlows() {
    pImpl_->clearFlows();
}

void ModelHandle::clearSystems() {
    pImpl_->clearSystems();
}

void ModelHandle::add(Flow *f) {
    pImpl_->add(f);
}

void ModelHandle::add(System *s) {
    pImpl_->add(s);
}

bool ModelHandle::beginSystems() const {
    return pImpl_->beginSystems();
}

bool ModelHandle::nextSystem() const {
    return pImpl_->nextSystem();
}

System *ModelHandle::getCurrentSystem() const {
    return pImpl_->getCurrentSystem();
}

bool ModelHandle::beginFlows() const {
    return pImpl_->beginFlows();
}

bool ModelHandle::nextFlow() const {
    return pImpl_->nextFlow();
}

Flow *ModelHandle::getCurrentFlow() const {
    return pImpl_->getCurrentFlow();
}