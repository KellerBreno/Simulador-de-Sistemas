//
// Created by brenokeller on 10/31/18.
//

#include <iostream>
#include <sstream>
#include "ModelImpl.h"
#include "FlowExp.h"
#include "FlowLog.h"
#include "SystemImpl.h"

ModelImpl::ModelImpl(const string &name) : name(name) {}

ModelImpl::ModelImpl(const ModelImpl &rhs) {
    if (&rhs == this) {
        return;
    }

    for (auto &system:rhs.systems) {
        auto *newSystem = dynamic_cast<SystemImpl *>(system);
        auto *copySystem = new SystemImpl((*newSystem));
        this->add(copySystem);
    }

    for (auto &flow:rhs.flows) {
        auto *flowExp = dynamic_cast<FlowExp *>(flow);
        if (flowExp != nullptr) {
            Flow *copyFlow = new FlowExp((*flowExp));
            for (auto &system : systems) {
                if (copyFlow->getSource() == system) {
                    copyFlow->setSource(system);
                } else if (copyFlow->getTarget() == system) {
                    copyFlow->setTarget(system);
                }
            }
            this->add(copyFlow);
            continue;
        }
        auto *flowLog = dynamic_cast<FlowLog *>(flow);
        if (flowLog != nullptr) {
            Flow *copyFlow = new FlowLog((*flowLog));
            for (auto &system : systems) {
                if (copyFlow->getSource() == system) {
                    copyFlow->setSource(system);
                } else if (copyFlow->getTarget() == system) {
                    copyFlow->setTarget(system);
                }
            }
            this->add(copyFlow);
            continue;
        }
    }

    this->setName(rhs.getName());
}

ModelImpl::~ModelImpl() {
    for (auto &system : systems) {
        system = nullptr;
    }
    systems.clear();
    for (auto &flow : flows) {
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
        flow = nullptr;
    }
    for (auto &system:systems) {
        system = nullptr;
    }
    flows.clear();
    systems.clear();

    for (auto &system:rhs.systems) {
        auto *newSystem = dynamic_cast<SystemImpl *>(system);
        auto *copySystem = new SystemImpl((*newSystem));
        this->add(copySystem);
    }

    for (auto &flow:rhs.flows) {
        auto *flowExp = dynamic_cast<FlowExp *>(flow);
        if (flowExp != nullptr) {
            Flow *copyFlow = new FlowExp((*flowExp));
            for (auto &system : systems) {
                if (copyFlow->getSource() == system) {
                    copyFlow->setSource(system);
                } else if (copyFlow->getTarget() == system) {
                    copyFlow->setTarget(system);
                }
            }
            this->add(copyFlow);
            continue;
        }
        auto *flowLog = dynamic_cast<FlowLog *>(flow);
        if (flowLog != nullptr) {
            Flow *copyFlow = new FlowLog((*flowLog));
            for (auto &system : systems) {
                if (copyFlow->getSource() == system) {
                    copyFlow->setSource(system);
                } else if (copyFlow->getTarget() == system) {
                    copyFlow->setTarget(system);
                }
            }
            this->add(copyFlow);
            continue;
        }
    }

    this->setName(rhs.getName());

    return *this;
}

bool ModelImpl::operator==(const Model &rhs) {
    bool resp = this->getName() == rhs.getName();

    ModelImpl model = (ModelImpl &) rhs;

    bool aux;
    for (System *system:systems) {
        aux = false;
        for (System *rhsSystem:model.systems) {
            if ((*system) == (*rhsSystem)) {
                aux = true;
                continue;
            }
        }
        if (!aux) {
            resp = false;
        }
    }

    for (auto &flow:flows) {
        aux = false;
        for (auto &rhsFlow:model.flows) {
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
