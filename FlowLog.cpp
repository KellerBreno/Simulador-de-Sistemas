//
// Created by brenokeller on 11/1/18.
//

#include "FlowLog.h"

FlowLog::FlowLog(const string &name) : name(name), source(nullptr), target(nullptr) {}

FlowLog::FlowLog(const FlowLog &rhs) {
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
}

FlowLog::~FlowLog() {

}

double FlowLog::execute() {
    if (target == nullptr) {
        return 0;
    }
    double aux = this->getTarget()->getValue();
    return 0.01 * aux * (1 - (aux / 70));
}

System *FlowLog::getSource() const {
    return source;
}

void FlowLog::setSource(System *source) {
    this->source = source;
}

System *FlowLog::getTarget() const {
    return target;
}

void FlowLog::setTarget(System *target) {
    this->target = target;
}

string FlowLog::getName() const {
    return name;
}

void FlowLog::setName(string name) {
    this->name = name;
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