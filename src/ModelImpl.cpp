//
// Created by brenokeller on 10/31/18.
//

#include <iostream>
#include <sstream>
#include "ModelImpl.h"

ModelImpl::ModelImpl(const string &name) : name(name) {}

ModelImpl::ModelImpl(const ModelImpl &rhs) {
    for (auto &flow:rhs.flows) {
        this->add(flow);
    }
    for (auto &system:rhs.systems) {
        this->add(system);
    }
    this->setName(rhs.getName());
}

ModelImpl::~ModelImpl() {
    for (auto &system : systems) {
        delete system;
        system = nullptr;
    }
    systems.clear();
    for (auto &flow : flows) {
        delete flow;
        flow = nullptr;
    }
    flows.clear();
}

void ModelImpl::simulate(int initialTime, int endTime) {
    simulate(initialTime, endTime, 1);
}

void ModelImpl::simulate(int initialTime, int endTime, int step) {
    double values[flows.size()];
    for (int time = initialTime; time <= endTime; time += step) {
        for (int i = 0; i < flows.size(); i++) {
            values[i] = flows[i]->execute();
        }
        for (int i = 0; i < flows.size(); i++) {
            System *source = flows[i]->getSource();
            System *target = flows[i]->getTarget();
            if (source != nullptr) {
                source->setValue(source->getValue() - values[i]);
            }
            if (target != nullptr) {
                target->setValue(target->getValue() + values[i]);
            }
        }
    }
}

void ModelImpl::add(Flow *f) {
    flows.push_back(f);
}

void ModelImpl::add(System *s) {
    systems.push_back(s);
}

Flow *ModelImpl::getFlow(string name) {
    for (auto &flow : flows) {
        if (flow->getName() == name) {
            return flow;
        }
    }
    return nullptr;
}

System *ModelImpl::getSystem(string name) {
    for (auto &system : systems) {
        if (system->getName() == name) {
            return system;
        }
    }
    return nullptr;
}

bool ModelImpl::remove(string name) {
    for (auto it = flows.begin(); it != flows.end(); ++it) {
        if ((*it)->getName() == name) {
            flows.erase(it);
            return true;
        }
    }
    for (auto it = systems.begin(); it != systems.end(); ++it) {
        if ((*it)->getName() == name) {
            systems.erase(it);
            return true;
        }
    }
    return false;
}

string ModelImpl::getName() const {
    return name;
}

void ModelImpl::setName(string name) {
    this->name = name;
}

string ModelImpl::report() {
    stringstream ss;
    ss << "===========================================================" << endl;
    ss << "Modelo: " << this->getName() << endl;
    ss << "----------------------- Sistemas --------------------------" << endl;
    for (auto &system:systems) {
        ss << "Sistema: " << system->getName() << " - " << system->getValue() << endl;
    }
    ss << "------------------------ Fluxos ---------------------------" << endl;
    for (auto &flow:flows) {
        ss << "Fluxo: " << flow->getName() << endl;
    }
    ss << "===========================================================" << endl;
    return ss.str();
}

ModelImpl &ModelImpl::operator=(const ModelImpl &rhs) {
    if (&rhs == this) {
        return *this;
    }
    for (auto &flow:flows) {
        delete flow;
        flow = nullptr;
    }
    for (auto &system:systems) {
        delete system;
        system = nullptr;
    }
    flows.clear();
    systems.clear();

    for (auto &flow:rhs.flows) {
        this->add(flow);
    }
    for (auto &system:rhs.systems) {
        this->add(system);
    }
    this->setName(rhs.getName());
    return *this;
}