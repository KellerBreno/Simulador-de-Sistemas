//
// Created by brenokeller on 10/31/18.
//

#include "SystemImpl.h"

SystemImpl::SystemImpl(const string &name, double value) : name(name), value(value) {}

SystemImpl::~SystemImpl() {}

double SystemImpl::getValue() {
    return value;
}

void SystemImpl::setValue(double value) {
    this->value = value;
}

string SystemImpl::getName() {
    return name;
}

void SystemImpl::setName(string name) {
    this->name = name;
}
