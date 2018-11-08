//
// Created by brenokeller on 11/1/18.
//

#ifndef SIMULADOR_FLOWLOG_H
#define SIMULADOR_FLOWLOG_H

#include "FlowImpl.h"

class FlowLog : public FlowImpl {

public:
    FlowLog(const string &name);

    virtual ~FlowLog();

    double execute() override;

private:
    FlowLog(const FlowLog &rhs);

    FlowLog &operator=(const FlowLog &rhs);
};


#endif //SIMULADOR_FLOWLOG_H
