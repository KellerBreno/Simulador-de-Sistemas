//
// Created by brenokeller on 11/1/18.
//

#ifndef SIMULADOR_FLOWLOG_H
#define SIMULADOR_FLOWLOG_H

#include "Flow.h"

class FlowLog : public Flow {

private:
    string name;
    System *source;
    System *target;

public:
    FlowLog(const string &name);

    double execute() override;

    System *getSource() const override;

    void setSource(System *source) override;

    System *getTarget() const override;

    void setTarget(System *target) override;

    string getName() const override;

    void setName(string name) override;

private:
    FlowLog(const FlowLog &rhs) {
        this->setTarget(rhs.getTarget());
        this->setSource(rhs.getSource());
        this->setName(rhs.getName());
    }

    FlowLog &operator=(const FlowLog &rhs) {
        if (&rhs == this) {
            return *this;
        }
        this->setTarget(rhs.getTarget());
        this->setSource(rhs.getSource());
        this->setName(rhs.getName());
        return *this;
    }
};


#endif //SIMULADOR_FLOWLOG_H
