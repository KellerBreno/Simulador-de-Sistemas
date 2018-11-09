//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_FLOWEXP_H
#define SIMULADOR_FLOWEXP_H

#include "FlowImpl.h"

class FlowExp : public FlowImpl {

private:
    double tax;

public:
    FlowExp(const string &name, double tax);

    virtual ~FlowExp();

    double execute() override;

    double getTax() const;

    void setTax(double tax);

private:
    FlowExp(const FlowExp &rhs);

    FlowExp &operator=(const FlowExp &rhs);

};


#endif //SIMULADOR_FLOWEXP_H
