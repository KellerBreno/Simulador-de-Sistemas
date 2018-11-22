//
// Created by brenokeller on 11/8/18.
//

#ifndef SIMULADOR_FLOWIMPL_H
#define SIMULADOR_FLOWIMPL_H


#include "Flow.h"

class FlowImpl : public Flow {
private:
    System *source_;
    System *target_;
    string name_;

public:
    FlowImpl(const string &name);

    FlowImpl(const string &name, System *source, System *target);

    FlowImpl(const Flow &rhs);

    virtual ~FlowImpl();

    System *getSource() const override;

    void setSource(System *source) override;

    System *getTarget() const override;

    void setTarget(System *target) override;

    string getName() const override;

    void setName(string name) override;

    bool operator==(const Flow &rhs) override;

    bool operator!=(const Flow &rhs) override;

    Flow& operator=(const Flow& rhs) override;
};


#endif //SIMULADOR_FLOWIMPL_H
