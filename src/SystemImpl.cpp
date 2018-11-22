//
// Created by brenokeller on 10/31/18.
//

#include "SystemImpl.h"

SystemImpl::SystemImpl(const string &name, double value) : name_(name), value_(value) {}

SystemImpl::SystemImpl(const System &rhs) {
    if (&rhs == this) {
        return;
    }
    this->setName(rhs.getName());
    this->setValue(rhs.getValue());
}

SystemImpl::~SystemImpl() {}

double SystemImpl::getValue() const {
    return value_;
}

void SystemImpl::setValue(double value) {
    this->value_ = value;
}

string SystemImpl::getName() const {
    return name_;
}

void SystemImpl::setName(string name) {
    this->name_ = name;
}

bool SystemImpl::operator==(const System &rhs) {
    return (this->getValue() == rhs.getValue()) && (this->getName() == rhs.getName());
}

bool SystemImpl::operator!=(const System &rhs) {
    return !(*this == rhs);
}

SystemImpl &SystemImpl::operator=(const SystemImpl &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setName(rhs.getName());
    this->setValue(rhs.getValue());
    return *this;
}