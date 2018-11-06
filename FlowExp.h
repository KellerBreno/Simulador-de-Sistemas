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
    double taxa;

public:
    FlowExp(const string &name, double taxa);

    virtual ~FlowExp();

    double execute() override;

    System *getSource() const override;

    void setSource(System *source) override;

    System *getTarget() const override;

    void setTarget(System *target) override;

    string getName() const override;

    void setName(string name) override;

    double getTaxa() const;

    void setTaxa(double taxa);

private:
    FlowExp(const FlowExp &rhs) {
        this->setTarget(rhs.getTarget());
        this->setSource(rhs.getSource());
        this->setName(rhs.getName());
        this->setTaxa(taxa);
    }

    FlowExp &operator=(const FlowExp &rhs) {
        if (&rhs == this) {
            return *this;
        }
        this->setTarget(rhs.getTarget());
        this->setSource(rhs.getSource());
        this->setName(rhs.getName());
        this->setTaxa(taxa);
        return *this;
    }

};


#endif //SIMULADOR_FLOWEXP_H
