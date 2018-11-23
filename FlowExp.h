//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_FLOWEXP_H
#define SIMULADOR_FLOWEXP_H

#include "src/FlowImpl.h"

class FlowExp : public FlowImpl {

public:
    FlowExp(const string &name);

    FlowExp(const string &name, System *source, System *target);

    FlowExp(const Flow &rhs);

    virtual ~FlowExp();

    double execute() override;

    Flow *clone() override;
};


#endif //SIMULADOR_FLOWEXP_H
