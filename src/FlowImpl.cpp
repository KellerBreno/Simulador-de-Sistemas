//
// Created by brenokeller on 11/8/18.
//

#include "FlowImpl.h"

FlowImpl::FlowImpl(const string &name) : name_(name), source_(nullptr), target_(nullptr) {}

FlowImpl::FlowImpl(const string &name, System *source, System *target) : name_(name), source_(source),
                                                                         target_(target) {}

FlowImpl::FlowImpl(const Flow &rhs) {
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
    return source_;
}

void FlowImpl::setSource(System *source) {
    this->source_ = source;
}

System *FlowImpl::getTarget() const {
    return target_;
}

void FlowImpl::setTarget(System *target) {
    this->target_ = target;
}

string FlowImpl::getName() const {
    return name_;
}

void FlowImpl::setName(string name) {
    this->name_ = name;
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

Flow &FlowImpl::operator=(const Flow &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
    return *this;
}