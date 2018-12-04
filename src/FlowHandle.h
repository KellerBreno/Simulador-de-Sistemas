//
// Created by brenokeller on 11/30/18.
//

#ifndef SIMULADOR_FLOWHANDLE_H
#define SIMULADOR_FLOWHANDLE_H

#include "Flow.h"
#include "FlowImpl.h"
#include "HandleBody.h"

template<class T_FLOW_IMPL>
class FlowHandle : public Flow, public Handle<T_FLOW_IMPL> {
public:
    FlowHandle(const string &name) : Handle<T_FLOW_IMPL>() {
        this->pImpl_->setName(name);
    }

    FlowHandle(const string &name, System *source, System *target) : Handle<T_FLOW_IMPL>() {
        this->pImpl_->setName(name);
        this->pImpl_->setSource(source);
        this->pImpl_->setTarget(target);
    }

    virtual ~FlowHandle() {

    }

    double execute() override {
        return this->pImpl_->execute();
    }

    System *getSource() const override {
        return this->pImpl_->getSource();
    }

    void setSource(System *source) override {
        this->pImpl_->setSource(source);
    }

    System *getTarget() const override {
        return this->pImpl_->getTarget();
    }

    void setTarget(System *target) override {
        this->pImpl_->setTarget(target);
    }

    string getName() const override {
        return this->pImpl_->getName();
    }

    void setName(string name) override {
        this->pImpl_->setName(name);
    }

    bool operator==(const Flow &rhs) override {
        bool resp = this->getName() == rhs.getName();

        resp = resp && (this->getSource() == rhs.getSource());
        resp = resp && (this->getTarget() == rhs.getTarget());

        return resp;
    }

    bool operator!=(const Flow &rhs) override {
        return !(operator==(rhs));
    }

protected:
    Flow *clone() override {
        Flow *f = new FlowHandle<T_FLOW_IMPL>(this->getName(), this->getSource(), this->getTarget());
        return f;
    }
};


#endif //SIMULADOR_FLOWHANDLE_H
