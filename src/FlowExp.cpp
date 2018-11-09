//
// Created by brenokeller on 10/31/18.
//

#include "FlowExp.h"

FlowExp::FlowExp(const string &name, double tax) : FlowImpl(name), tax(tax) {}

FlowExp::FlowExp(const FlowExp &rhs) : FlowImpl(rhs.getName()) {
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setTax(rhs.getTax());
}

FlowExp::~FlowExp() {

}

double FlowExp::execute() {
    if (this->getSource() == nullptr) {
        return 0;
    }
    return tax * this->getSource()->getValue();
}

double FlowExp::getTax() const {
    return tax;
}

void FlowExp::setTax(double tax) {
    this->tax = tax;
}

FlowExp &FlowExp::operator=(const FlowExp &rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->setTarget(rhs.getTarget());
    this->setSource(rhs.getSource());
    this->setName(rhs.getName());
    this->setTax(rhs.getTax());
    return *this;
}
