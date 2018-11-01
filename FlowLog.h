//
// Created by brenokeller on 11/1/18.
//

#ifndef SIMULADOR_FLOWLOG_H
#define SIMULADOR_FLOWLOG_H

#include "Flow.h"

class FlowLog : public Flow{

private:
    string name;
    System *source;
    System *target;

public:
    FlowLog(const string &name);

    double execute() override;

    System *getSource() override;

    void setSource(System *source) override;

    System *getTarget() override;

    void setTarget(System *target) override;

    string getName() override;

    void setName(string name) override;
};


#endif //SIMULADOR_FLOWLOG_H
