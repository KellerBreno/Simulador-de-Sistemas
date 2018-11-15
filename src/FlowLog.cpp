//
// Created by brenokeller on 11/1/18.
//

#include "FlowLog.h"

FlowLog::FlowLog(const string &name) : FlowImpl(name) {}

FlowLog::FlowLog(const FlowLog &rhs) : FlowImpl(rhs.getName()) {
    if (&rhs == this) {
        return;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
}

FlowLog::~FlowLog() {

}

double FlowLog::execute() {
    if (this->getTarget() == nullptr) {
        return 0;
    }
    double aux = this->getTarget()->getValue();
    return 0.01 * aux * (1 - (aux / 70));
}

FlowLog &FlowLog::operator=(const FlowLog &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
    return *this;
}