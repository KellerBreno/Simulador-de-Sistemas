//
// Created by brenokeller on 12/4/18.
//

#include "ModelHandle.h"

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

    for (Model::systemIterator it = model->beginSystems(); it != model->endSystems(); ++it) {
        m->createSystem((*it)->getName(), (*it)->getValue());
    }

    for (Model::flowIterator it = model->beginFlows(); it != model->endFlows(); ++it) {
        Flow *copy = m->createFlow((*it));
        for (Model::systemIterator itSystem = m->beginSystems(); itSystem != m->endSystems();
             ++itSystem) {
            if ((copy->getSource() != nullptr) && *(copy->getSource()) == *((*itSystem))) {
                copy->setSource((*itSystem));
            } else if ((copy->getTarget() != nullptr) && *(copy->getTarget()) == *((*itSystem))) {
                copy->setTarget((*itSystem));
            }
        }
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
    for (Model::systemIterator it = this->beginSystems(); it != this->endSystems(); ++it) {
        aux = false;
        for (Model::systemIterator rhsIt = rhs.beginSystems(); rhsIt != rhs.endSystems(); ++rhsIt) {
            if (*(*it) == *(*rhsIt)) {
                aux = true;
                continue;
            }
        }
        if (!aux) {
            resp = false;
        }
    }

    for (Model::flowIterator it = this->beginFlows(); it != this->endFlows(); ++it) {
        aux = false;
        for (Model::flowIterator rhsIt = rhs.beginFlows(); rhsIt != rhs.endFlows(); ++rhsIt) {
            if (*(*it) == *(*rhsIt)) {
                aux = true;
                continue;
            }
        }
        if (!aux) {
            resp = false;
        }
    }

    return resp;
}

bool ModelHandle::operator!=(const Model &rhs) {
    return !(operator==(rhs));
}

Model &ModelHandle::operator=(Model &rhs) {
    for (Model::systemIterator it = this->beginSystems(); it != this->endSystems(); ++it) {
        // TODO Slicing
        delete (*it);
        (*it) = nullptr;
    }

    for (Model::flowIterator it = this->beginFlows(); it != this->endFlows(); ++it) {
        // TODO Slicing
        delete (*it);
        (*it) = nullptr;
    }

    this->clearFlows();

    this->clearSystems();

    for (Model::systemIterator it = rhs.beginSystems(); it != rhs.endSystems(); ++it) {
        this->createSystem((*it)->getName(), (*it)->getValue());
    }

    for (Model::flowIterator it = rhs.beginFlows(); it != rhs.endFlows(); ++it) {
        Flow *copy = this->createFlow((*it));
        for (Model::systemIterator itSystem = this->beginSystems(); itSystem != this->endSystems(); ++itSystem) {
            if ((copy->getSource() != nullptr) && *(copy->getSource()) == *((*itSystem))) {
                copy->setSource((*itSystem));
            } else if ((copy->getTarget() != nullptr) && *(copy->getTarget()) == *((*itSystem))) {
                copy->setTarget((*itSystem));
            }
        }
    }

    this->setName(rhs.getName());

    return *this;
}

Model::flowIterator ModelHandle::beginFlows() const {
    return pImpl_->beginFlows();
}

Model::flowIterator ModelHandle::endFlows() const {
    return pImpl_->endFlows();
}

void ModelHandle::clearFlows() {
    pImpl_->clearFlows();
}

Model::systemIterator ModelHandle::beginSystems() const {
    return pImpl_->beginSystems();
}

Model::systemIterator ModelHandle::endSystems() const {
    return pImpl_->endSystems();
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