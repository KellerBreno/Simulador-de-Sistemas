//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_MODEL_H
#define SIMULADOR_MODEL_H

#include <string>
#include "System.h"
#include "Flow.h"

using namespace std;

class Model {
public:
    virtual ~Model() {};

    virtual void simulate(int initialTime, int endTime) = 0;

    virtual void simulate(int initialTime, int endTime, int step) = 0;

    virtual void add(Flow *f) = 0;

    virtual void add(System *s) = 0;

    virtual Flow *getFlow(string name) = 0;

    virtual System *getSystem(string name) = 0;

    virtual bool remove(string name) = 0;

    virtual string getName() const = 0;

    virtual void setName(string name) = 0;

    virtual string report() = 0;
};


#endif //SIMULADOR_MODEL_H
