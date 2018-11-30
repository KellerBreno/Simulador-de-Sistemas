/*!
* \file ModelImpl.cpp
* Arquivo contendo a Implementação da Classe ModelImpl
*
* \author Breno Keller
* \since 31/10/18
*/

#include <iostream>
#include <sstream>
#include "ModelImpl.h"
#include "SystemHandle.h"

vector<Model *> ModelImpl::models_;

// static vector<Model *> models_;

Model *Model::createModel(string name) {
    return ModelImpl::createModel(name);
}

Model *ModelImpl::createModel(string name) {
    if (name.empty()) {
        return nullptr;
    }
    Model *m = new ModelImpl(name);
    models_.push_back(m);
    return m;
};

Model *Model::createModel(Model *model) {
    return ModelImpl::createModel(model);
}

Model *ModelImpl::createModel(Model *model) {
    ModelImpl *cast = dynamic_cast<ModelImpl *>(model);
    Model *m = new ModelImpl((*cast));
    models_.push_back(m);
    return m;
}

bool Model::deleteModel(string name) {
    return ModelImpl::deleteModel(name);
}

bool ModelImpl::deleteModel(string name) {
    for (auto it = models_.begin(); it != models_.end(); ++it) {
        ModelImpl *m = dynamic_cast<ModelImpl *>(*it);
        if (m->getName() == name) {
            models_.erase(it);
            delete m;
            return true;
        }
    }
    return false;
};

ModelImpl::ModelImpl(const string &name) : name_(name) {}

ModelImpl::ModelImpl(const ModelImpl &rhs) {
    if (&rhs == this) {
        return;
    }

    for (System *system:rhs.systems_) {
        this->createSystem(system->getName(), system->getValue());
    }

    for (Flow *flow:rhs.flows_) {
        Flow *copy = this->createFlow(flow);
        for (System *system : systems_) {
            if ((copy->getSource() != nullptr) && *(copy->getSource()) == (*system)) {
                copy->setSource(system);
            } else if ((copy->getTarget() != nullptr) && *(copy->getTarget()) == (*system)) {
                copy->setTarget(system);
            }
        }
    }

    this->setName(rhs.getName());
}

ModelImpl::~ModelImpl() {
    for (auto &system : systems_) {
        delete (SystemHandle *) system;
        system = nullptr;
    }
    systems_.clear();

    for (auto &flow : flows_) {
        // Assumindo que não foram adicionados novos atributos é possivel deleta-la assim
        delete (FlowImpl *) flow;
        flow = nullptr;
    }
    flows_.clear();
}

void ModelImpl::simulate(int initialTime, int endTime) {
    simulate(initialTime, endTime, 1);
}

void ModelImpl::simulate(int initialTime, int endTime, int step) {
    double values[flows_.size()];
    for (int time = initialTime; time <= endTime; time += step) {
        for (int i = 0; i < flows_.size(); i++) {
            values[i] = flows_[i]->execute();
        }
        for (int i = 0; i < flows_.size(); i++) {
            System *source = flows_[i]->getSource();
            System *target = flows_[i]->getTarget();
            if (source != nullptr) {
                source->setValue(source->getValue() - values[i]);
            }
            if (target != nullptr) {
                target->setValue(target->getValue() + values[i]);
            }
        }
    }
}

Flow *ModelImpl::getFlow(string name) {
    for (auto &flow : flows_) {
        if (flow->getName() == name) {
            return flow;
        }
    }
    return nullptr;
}

System *ModelImpl::getSystem(string name) {
    for (System *&system : systems_) {
        if (system->getName() == name) {
            return system;
        }
    }
    return nullptr;
}

bool ModelImpl::deleteFlow(string name) {
    for (auto it = flows_.begin(); it != flows_.end(); ++it) {
        // TODO Slicing
        Flow *f = dynamic_cast<Flow *>(*it);
        if (f->getName() == name) {
            flows_.erase(it);
            delete f;
            return true;
        }
    }
    return false;
}

bool ModelImpl::deleteSystem(string name) {
    for (auto it = systems_.begin(); it != systems_.end(); ++it) {
        SystemHandle *s = dynamic_cast<SystemHandle *>(*it);
        if (s->getName() == name) {
            systems_.erase(it);
            delete s;
            return true;
        }
    }
    return false;
}

string ModelImpl::getName() const {
    return name_;
}

void ModelImpl::setName(string name) {
    this->name_ = name;
}

string ModelImpl::report() {
    stringstream ss;
    ss << "===========================================================" << endl;
    ss << "Modelo: " << this->getName() << endl;
    ss << "----------------------- Sistemas --------------------------" << endl;
    for (auto &system:systems_) {
        ss << "Sistema: " << system->getName() << " - " << system->getValue() << endl;
    }
    ss << "------------------------ Fluxos ---------------------------" << endl;
    for (auto &flow:flows_) {
        ss << "Fluxo: " << flow->getName() << endl;
    }
    ss << "===========================================================" << endl;
    return ss.str();
}

System *ModelImpl::createSystem(string name) {
    return this->createSystem(name, 0);
}

System *ModelImpl::createSystem(string name, double initValue) {
    System *system = new SystemHandle(name, initValue);
    add(system);
    return system;
}

System *ModelImpl::createSystem(System *system) {
    System *copy = new SystemHandle(system->getName(), system->getValue());
    add(copy);
    return copy;
}

bool ModelImpl::operator==(const Model &rhs) {
    bool resp = this->getName() == rhs.getName();

    ModelImpl model = (ModelImpl &) rhs;

    bool aux;
    for (System *system:systems_) {
        aux = false;
        for (System *rhsSystem:model.systems_) {
            if ((*system) == (*rhsSystem)) {
                aux = true;
                continue;
            }
        }
        if (!aux) {
            resp = false;
        }
    }

    for (auto &flow:flows_) {
        aux = false;
        for (auto &rhsFlow:model.flows_) {
            if (flow == rhsFlow) {
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

bool ModelImpl::operator!=(const Model &rhs) {
    return !(*this == rhs);
}

Model &ModelImpl::operator=(Model &rhs) {
    if (&rhs == this) {
        return *this;
    }

    for (Model::systemIterator it = rhs.beginSystems(); it != rhs.endSystems(); ++it) {
        this->createSystem((*it));
    }

    for (Model::flowIterator it = rhs.beginFlows(); it != rhs.endFlows(); ++it) {
        Flow *copy = this->createFlow((*it));
        for (System *system : systems_) {
            if ((copy->getSource() != nullptr) && *(copy->getSource()) == (*system)) {
                copy->setSource(system);
            } else if ((copy->getTarget() != nullptr) && *(copy->getTarget()) == (*system)) {
                copy->setTarget(system);
            }
        }
    }

    this->setName(rhs.getName());

    return *this;
}

void ModelImpl::add(Flow *f) {
    flows_.push_back(f);
}

void ModelImpl::add(System *s) {
    systems_.push_back(s);
}

Model::flowIterator ModelImpl::beginFlows() {
    return flows_.begin();
}

Model::flowIterator ModelImpl::endFlows() {
    return flows_.end();

}

Model::systemIterator ModelImpl::beginSystems() {
    return systems_.begin();
}

Model::systemIterator ModelImpl::endSystems() {
    return systems_.end();
}