//
// Created by brenokeller on 10/31/18.
//

#include "SystemImpl.h"

SystemImpl::SystemImpl(const string &name, double value) : name(name), value(value) {}

SystemImpl::SystemImpl(const SystemImpl &rhs) {
    if (&rhs == this) {
        return;
    }
    this->setName(rhs.getName());
    this->setValue(rhs.getValue());
}

SystemImpl::~SystemImpl() {}

double SystemImpl::getValue() const {
    return value;
}

void SystemImpl::setValue(double value) {
    this->value = value;
}

string SystemImpl::getName() const {
    return name;
}

void SystemImpl::setName(string name) {
    this->name = name;
}

SystemImpl &SystemImpl::operator=(const SystemImpl &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setName(rhs.getName());
    this->setValue(rhs.getValue());
    return *this;
}
