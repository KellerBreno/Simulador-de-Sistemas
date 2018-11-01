//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_FLOWEXP_H
#define SIMULADOR_FLOWEXP_H

#include "Flow.h"

using namespace std;

class FlowExp : public Flow {

private:
    System *source;
    System *target;
    string name;

public:
    FlowExp(const string &name);

    virtual ~FlowExp();

    double execute() override;

    System *getSource() override;

    void setSource(System *source) override;

    System *getTarget() override;

    void setTarget(System *target) override;

    string getName() override;

    void setName(string name) override;
};


#endif //SIMULADOR_FLOWEXP_H
