//
// Created by brenokeller on 11/8/18.
//

#include "FlowImpl.h"
#include "SystemImpl.h"

FlowImpl::FlowImpl(const string &name) : name(name), source(nullptr), target(nullptr) {}

FlowImpl::FlowImpl(const FlowImpl &rhs) {
    if (&rhs == this) {
        return;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
}

FlowImpl::~FlowImpl() {

}

System *FlowImpl::getSource() const {
    return source;
}

void FlowImpl::setSource(System *source) {
    this->source = source;
}

System *FlowImpl::getTarget() const {
    return target;
}

void FlowImpl::setTarget(System *target) {
    this->target = target;
}

string FlowImpl::getName() const {
    return name;
}

void FlowImpl::setName(string name) {
    this->name = name;
}

FlowImpl &FlowImpl::operator=(const FlowImpl &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
    return *this;
}

bool FlowImpl::operator==(const Flow &rhs) {
    bool resp = this->getName() == rhs.getName();

    resp = resp && (this->getSource() == rhs.getSource());
    resp = resp && (this->getTarget() == rhs.getTarget());

    return resp;
}

bool FlowImpl::operator!=(const Flow &rhs) {
    return !(*this == rhs);
}