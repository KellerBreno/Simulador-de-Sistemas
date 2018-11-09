//
// Created by brenokeller on 11/8/18.
//

#ifndef SIMULADOR_FLOWIMPL_H
#define SIMULADOR_FLOWIMPL_H


#include "Flow.h"

class FlowImpl : public Flow {
private:
    System *source;
    System *target;
    string name;

public:
    FlowImpl(const string &name);

    FlowImpl(const FlowImpl &rhs);

    virtual ~FlowImpl();

    System *getSource() const override;

    void setSource(System *source) override;

    System *getTarget() const override;

    void setTarget(System *target) override;

    string getName() const override;

    void setName(string name) override;

    FlowImpl &operator=(const FlowImpl &rhs);

};


#endif //SIMULADOR_FLOWIMPL_H
