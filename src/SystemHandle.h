//
// Created by brenokeller on 11/29/18.
//

#ifndef SIMULADOR_SYSTEMHANDLE_H
#define SIMULADOR_SYSTEMHANDLE_H

#include "System.h"
#include "SystemBody.h"

class SystemHandle : public System, public Handle<SystemBody> {
public:
    SystemHandle(string name, double value);

    virtual ~SystemHandle();

    double getValue() const override;

    void setValue(double value) override;

    string getName() const override;

    void setName(string name) override;

    bool operator==(const System &rhs);

    bool operator!=(const System &rhs);
};


#endif //SIMULADOR_SYSTEMHANDLE_H