//
// Created by brenokeller on 10/31/18.
//

#include "FlowExp.h"

FlowExp::FlowExp(const string &name, double taxa) : FlowImpl(name), taxa(taxa) {}

FlowExp::FlowExp(const FlowExp &rhs) : FlowImpl(rhs.getName()) {
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setTaxa(taxa);
}

FlowExp::~FlowExp() {

}

double FlowExp::execute() {
    if (this->getSource() == nullptr) {
        return 0;
    }
    return taxa * this->getSource()->getValue();
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
