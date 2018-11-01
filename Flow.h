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
    virtual double execute() = 0;

    virtual System *getSource() = 0;

    virtual void setSource(System *source) = 0;

    virtual System *getTarget() = 0;

    virtual void setTarget(System *target) = 0;

    virtual string getName() = 0;

    virtual void setName(string name) = 0;
};


#endif //SIMULADOR_FLOW_H
