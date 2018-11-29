//
// Created by brenokeller on 11/29/18.
//

#ifndef SIMULADOR_SYSTEMHANDLE_H
#define SIMULADOR_SYSTEMHANDLE_H

#include "System.h"
#include "SystemImpl.h"

class SystemHandle : public System, public Handle<SystemImpl> {
public:
    SystemHandle(string name, double value);

    double getValue() const override;

    void setValue(double value) override;

    string getName() const override;

    void setName(string name) override;

    bool operator==(const System &rhs) override;

    bool operator!=(const System &rhs) override;
};


#endif //SIMULADOR_SYSTEMHANDLE_H
