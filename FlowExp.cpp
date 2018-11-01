//
// Created by brenokeller on 10/31/18.
//

#include "FlowExp.h"

FlowExp::FlowExp(const string &name, double taxa) : name(name), taxa(taxa), source(nullptr), target(nullptr) {}

FlowExp::~FlowExp() {

}

double FlowExp::execute() {
    if (source == nullptr) {
        return 0;
    }
    return taxa * source->getValue();
}

System *FlowExp::getSource() {
    return source;
}

void FlowExp::setSource(System *source) {
    this->source = source;
}

System *FlowExp::getTarget() {
    return target;
}

void FlowExp::setTarget(System *target) {
    this->target = target;
}

string FlowExp::getName() {
    return name;
}

void FlowExp::setName(string name) {
    this->name = name;
}