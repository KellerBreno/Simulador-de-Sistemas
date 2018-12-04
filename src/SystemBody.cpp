/*!
* \file SystemImpl.cpp
* Arquivo contendo a Implementação da Classe System
*
* \author Breno Keller
* \since 31/10/18
*/

#include "SystemBody.h"

SystemBody::SystemBody() {}

SystemBody::SystemBody(const string &name, double value) : name_(name), value_(value) {}

SystemBody::SystemBody(const SystemBody &rhs) {
    if (&rhs == this) {
        return;
    }
    this->setName(rhs.getName());
    this->setValue(rhs.getValue());
}

SystemBody::~SystemBody() {}

double SystemBody::getValue() const {
    return value_;
}

void SystemBody::setValue(double value) {
    this->value_ = value;
}

string SystemBody::getName() const {
    return name_;
}

void SystemBody::setName(string name) {
    this->name_ = name;
}

bool SystemBody::operator==(const SystemBody &rhs) {
    return (this->getValue() == rhs.getValue()) && (this->getName() == rhs.getName());
}

bool SystemBody::operator!=(const SystemBody &rhs) {
    return !(*this == rhs);
}

SystemBody &SystemBody::operator=(const SystemBody &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setName(rhs.getName());
    this->setValue(rhs.getValue());
    return *this;
}