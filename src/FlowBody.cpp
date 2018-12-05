/*!
* \file FlowImpl.cpp
* Arquivo contendo a Implementação da Classe Abstrata FlowImpl
*
* \author Breno Keller
* \since 08/11/18
*/

#include "FlowBody.h"

FlowBody::FlowBody() : source_(nullptr), target_(nullptr) {}

FlowBody::FlowBody(const string &name) : name_(name), source_(nullptr), target_(nullptr) {}

FlowBody::FlowBody(const string &name, System *source, System *target) : name_(name), source_(source),
                                                                         target_(target) {}

FlowBody::FlowBody(const FlowBody &rhs) {
    if (&rhs == this) {
        return;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
}

FlowBody::~FlowBody() {

}

System *FlowBody::getSource() const {
    return source_;
}

void FlowBody::setSource(System *source) {
    this->source_ = source;
}

System *FlowBody::getTarget() const {
    return target_;
}

void FlowBody::setTarget(System *target) {
    this->target_ = target;
}

string FlowBody::getName() const {
    return name_;
}

void FlowBody::setName(string name) {
    this->name_ = name;
}

bool FlowBody::operator==(const FlowBody &rhs) {
    bool resp = this->getName() == rhs.getName();

    resp = resp && (this->getSource() == rhs.getSource());
    resp = resp && (this->getTarget() == rhs.getTarget());

    return resp;
}

bool FlowBody::operator!=(const FlowBody &rhs) {
    return !(*this == rhs);
}

FlowBody &FlowBody::operator=(const FlowBody &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
    return *this;
}