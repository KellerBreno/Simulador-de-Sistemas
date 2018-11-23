//
// Created by brenokeller on 11/1/18.
//

#include "FlowLog.h"

FlowLog::FlowLog(const string &name) : FlowImpl(name) {}

FlowLog::FlowLog(const string &name, System *source, System *target) : FlowImpl(name, source, target) {}

FlowLog::FlowLog(const Flow &rhs) : FlowImpl(rhs) {}

FlowLog::~FlowLog() {

}

double FlowLog::execute() {
    if (this->getTarget() == nullptr) {
        return 0;
    }
    double aux = this->getTarget()->getValue();
    return 0.01 * aux * (1 - (aux / 70));
}

Flow *FlowLog::clone() {
    Flow *flow = new FlowLog(*this);
    return flow;
}
