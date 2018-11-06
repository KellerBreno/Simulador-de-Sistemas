//
// Created by brenokeller on 10/31/18.
//

#include "FlowExp.h"

FlowExp::FlowExp(const string &name, double taxa) : name(name), taxa(taxa), source(nullptr), target(nullptr) {}

FlowExp::FlowExp(const FlowExp &rhs) {
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
    this->setTaxa(taxa);
}

FlowExp::~FlowExp() {

}

double FlowExp::execute() {
    if (source == nullptr) {
        return 0;
    }
    return taxa * source->getValue();
}

System *FlowExp::getSource() const {
    return source;
}

void FlowExp::setSource(System *source) {
    this->source = source;
}

System *FlowExp::getTarget() const {
    return target;
}

void FlowExp::setTarget(System *target) {
    this->target = target;
}

string FlowExp::getName() const {
    return name;
}

void FlowExp::setName(string name) {
    this->name = name;
}

double FlowExp::getTaxa() const {
    return taxa;
}

void FlowExp::setTaxa(double taxa) {
    FlowExp::taxa = taxa;
}

FlowExp &FlowExp::operator=(const FlowExp &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
    this->setTaxa(taxa);
    return *this;
}
