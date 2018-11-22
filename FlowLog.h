//
// Created by brenokeller on 11/1/18.
//

#ifndef SIMULADOR_FLOWLOG_H
#define SIMULADOR_FLOWLOG_H

#include "src/FlowImpl.h"

class FlowLog : public FlowImpl {

public:
    FlowLog(const string &name);

    FlowLog(const FlowLog &rhs);

    virtual ~FlowLog();

    double execute() override;

    FlowLog &operator=(const FlowLog &rhs);
};


#endif //SIMULADOR_FLOWLOG_H
