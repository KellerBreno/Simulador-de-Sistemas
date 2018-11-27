//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_FLOW_H
#define SIMULADOR_FLOW_H

#include <string>
#include "System.h"

using namespace std;

class Flow {
public:
    friend class Model;

    // Testes Fluxos
    friend class TestFlow;

    virtual double execute() = 0;

    virtual System *getSource() const = 0;

    virtual void setSource(System *source) = 0;

    virtual System *getTarget() const = 0;

    virtual void setTarget(System *target) = 0;

    virtual string getName() const = 0;

    virtual void setName(string name) = 0;

    virtual bool operator==(const Flow &rhs) = 0;

    virtual bool operator!=(const Flow &rhs) = 0;

    virtual Flow &operator=(const Flow &rhs) = 0;

protected:
    virtual Flow *clone() = 0;

};


#endif //SIMULADOR_FLOW_H
