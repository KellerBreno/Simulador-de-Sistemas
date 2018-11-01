//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_SYSTEM_H
#define SIMULADOR_SYSTEM_H

#include <string>

using namespace std;

class System {
public:
    virtual double getValue() = 0;

    virtual void setValue(double value) = 0;

    virtual string getName() = 0;

    virtual void setName(string name) = 0;
};


#endif //SIMULADOR_SYSTEM_H