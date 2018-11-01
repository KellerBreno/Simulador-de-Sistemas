//
// Created by brenokeller on 10/31/18.
//

#include "ModelImpl.h"

ModelImpl::ModelImpl(const string &name) : name(name) {}

// TODO
ModelImpl::~ModelImpl() {}

void ModelImpl::simulate(int initialTime, int endTime) {
    simulate(initialTime, endTime, 1);
}

void ModelImpl::simulate(int initialTime, int endTime, int step) {
    double values[flows.size()];
    for (int time = initialTime; time <= endTime; time += step) {
        for (int i = 0; i <= flows.size(); ++i) {
            values[i] = flows[i]->execute();
        }
        for (int i = 0; i <= flows.size(); ++i) {
            System *source = flows[i]->getSource();
            System *target = flows[i]->getTarget();
            source->setValue(source->getValue() - values[i]);
            target->setValue(target->getValue() - values[i]);
        }
    }
}

bool ModelImpl::add(Flow *f) {
    for (auto &flow:flows) {
        if (flow->getName() == f->getName()) {
            return false;
        }
    }
    for (auto &system:systems) {
        if (system->getName() == f->getName()) {
            return false;
        }
    }
    flows.push_back(f);
    return true;
}

bool ModelImpl::add(System *s) {
    for (auto &flow:flows) {
        if (flow->getName() == s->getName()) {
            return false;
        }
    }
    for (auto &system:systems) {
        if (system->getName() == s->getName()) {
            return false;
        }
    }
    systems.push_back(s);
    return true;

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

string ModelImpl::getName() {
    return name;
}

void ModelImpl::setName(string name) {
    this->name = name;
}

// TODO
Flow *ModelImpl::getFlows() {
    return nullptr;
}

// TODO
System *ModelImpl::getSystems() {
    return nullptr;
}

// TODO
string ModelImpl::report() {
    return std::__cxx11::string();
}