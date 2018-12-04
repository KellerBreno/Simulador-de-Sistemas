//
// Created by brenokeller on 11/29/18.
//

#ifndef SIMULADOR_SYSTEMHANDLE_H
#define SIMULADOR_SYSTEMHANDLE_H

#include "System.h"
#include "SystemImpl.h"

class SystemHandle : public System, public Handle<SystemImpl> {
public:
    SystemHandle(string name, double value) : Handle<SystemImpl>() {
        pImpl_->setName(name);
        pImpl_->setValue(value);
    }

    virtual ~SystemHandle() {}

    double getValue() const override {
        return pImpl_->getValue();
    }

    void setValue(double value) override {
        pImpl_->setValue(value);
    }

    string getName() const override {
        return pImpl_->getName();
    }

    void setName(string name) override {
        pImpl_->setName(name);
    }

    bool operator==(const System &rhs) {
        return (this->getValue() == rhs.getValue()) && (this->getName() == rhs.getName());
    }

    bool operator!=(const System &rhs) override {
        return !(operator==(rhs));
    }
};


#endif //SIMULADOR_SYSTEMHANDLE_H