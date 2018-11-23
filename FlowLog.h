//
// Created by brenokeller on 11/1/18.
//

#ifndef SIMULADOR_FLOWLOG_H
#define SIMULADOR_FLOWLOG_H

#include "src/FlowImpl.h"

class FlowLog : public FlowImpl {

public:
    FlowLog(const string &name);

    FlowLog(const string &name, System *source, System *target);

    FlowLog(const Flow &rhs);

    virtual ~FlowLog();

    double execute() override;

    Flow* clone() override;
};


#endif //SIMULADOR_FLOWLOG_H
