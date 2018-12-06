/*!
* \file SystemHandle.cpp
* Arquivo contendo a Implementação da Classe SystemHandle
*
* \author Breno Keller
* \since 04/12/18
*/

#include "SystemHandle.h"

SystemHandle::SystemHandle(string name, double value) : Handle() {
    pImpl_->setName(name);
    pImpl_->setValue(value);
}

SystemHandle::~SystemHandle() {}

double SystemHandle::getValue() const {
    return pImpl_->getValue();
}

void SystemHandle::setValue(double value) {
    pImpl_->setValue(value);
}

string SystemHandle::getName() const {
    return pImpl_->getName();
}

void SystemHandle::setName(string name) {
    pImpl_->setName(name);
}

bool SystemHandle::operator==(const System &rhs) {
    return (this->getValue() == rhs.getValue()) && (this->getName() == rhs.getName());
}

bool SystemHandle::operator!=(const System &rhs) {
    return !(operator==(rhs));
}