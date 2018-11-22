//
// Created by brenokeller on 10/31/18.
//

#include "FlowExp.h"

FlowExp::FlowExp(const string &name) : FlowImpl(name) {}

FlowExp::FlowExp(const string &name, System *source, System *target) : FlowImpl(name, source, target) {}

FlowExp::FlowExp(const Flow &rhs) : FlowImpl(rhs) {}

FlowExp::~FlowExp() {

}

double FlowExp::execute() {
    if (this->getSource() == nullptr) {
        return 0;
    }
    return 0.01 * this->getSource()->getValue();
}
