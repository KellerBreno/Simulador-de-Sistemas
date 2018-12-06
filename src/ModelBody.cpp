/*!
* \file ModelBody.cpp
* Arquivo contendo a Implementação da Classe ModelBody
*
* \author Breno Keller
* \since 31/10/18
*/

#include <iostream>
#include <sstream>
#include "ModelBody.h"
#include "SystemHandle.h"

ModelBody::ModelBody() {

}

ModelBody::ModelBody(const string &name) : name_(name) {}

ModelBody::ModelBody(const ModelBody &rhs) {
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

ModelBody::~ModelBody() {
    for (auto &system : systems_) {
        delete (SystemHandle *) system;
        system = nullptr;
    }
    systems_.clear();

    for (auto &flow : flows_) {
        // Assumindo que não foram adicionados novos atributos é possivel deleta-la assim
        delete (FlowBody *) flow;
        flow = nullptr;
    }
    flows_.clear();
}

void ModelBody::simulate(int initialTime, int endTime) {
    simulate(initialTime, endTime, 1);
}

void ModelBody::simulate(int initialTime, int endTime, int step) {
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

Flow *ModelBody::getFlow(string name) {
    for (auto &flow : flows_) {
        if (flow->getName() == name) {
            return flow;
        }
    }
    return nullptr;
}

System *ModelBody::getSystem(string name) {
    for (System *&system : systems_) {
        if (system->getName() == name) {
            return system;
        }
    }
    return nullptr;
}

bool ModelBody::deleteFlow(string name) {
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

bool ModelBody::deleteSystem(string name) {
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

string ModelBody::getName() const {
    return name_;
}

void ModelBody::setName(string name) {
    this->name_ = name;
}

string ModelBody::report() {
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

System *ModelBody::createSystem(string name) {
    return this->createSystem(name, 0);
}

System *ModelBody::createSystem(string name, double initValue) {
    System *system = new SystemHandle(name, initValue);
    add(system);
    return system;
}

System *ModelBody::createSystem(System *system) {
    System *copy = new SystemHandle(system->getName(), system->getValue());
    add(copy);
    return copy;
}

bool ModelBody::operator==(const ModelBody &rhs) {
    bool resp = this->getName() == rhs.getName();

    ModelBody model = rhs;

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

bool ModelBody::operator!=(const ModelBody &rhs) {
    return !(*this == rhs);
}

ModelBody &ModelBody::operator=(ModelBody &rhs) {
    if (&rhs == this) {
        return *this;
    }

    if (rhs.beginSystems()) {
        do {
            this->createSystem(rhs.getCurrentSystem());
        } while (rhs.nextSystem());
    }

    if (rhs.beginFlows()) {
        do {
            Flow *copy = this->createFlow(rhs.getCurrentFlow());
            for (System *system : systems_) {
                if ((copy->getSource() != nullptr) && *(copy->getSource()) == (*system)) {
                    copy->setSource(system);
                } else if ((copy->getTarget() != nullptr) && *(copy->getTarget()) == (*system)) {
                    copy->setTarget(system);
                }
            }
        } while (rhs.nextFlow());
    }

    this->setName(rhs.getName());

    return *this;
}

void ModelBody::add(Flow *f) {
    flows_.push_back(f);
}

void ModelBody::add(System *s) {
    systems_.push_back(s);
}

void ModelBody::clearFlows() {
    flows_.clear();
}

void ModelBody::clearSystems() {
    systems_.clear();
}

bool ModelBody::beginSystems() {
    if (systems_.empty()) {
        return false;
    }
    itSystem = systems_.begin();
    return true;
}

bool ModelBody::nextSystem() {
    ++itSystem;
    return (itSystem != systems_.end());
}

System *ModelBody::getCurrentSystem() {
    return (*itSystem);
}

bool ModelBody::beginFlows() {
    if (flows_.empty()) {
        return false;
    }
    itFlow = flows_.begin();
    return true;
}

bool ModelBody::nextFlow() {
    ++itFlow;
    return (itFlow != flows_.end());
}

Flow *ModelBody::getCurrentFlow() {
    return (*itFlow);
}
