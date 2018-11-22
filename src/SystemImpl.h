//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_SYSTEMIMPL_H
#define SIMULADOR_SYSTEMIMPL_H

#include "System.h"

using namespace std;

class SystemImpl : public System {

private:
    string name_;
    double value_;

public:
    SystemImpl(const string &name, double value);

    SystemImpl(const System &rhs);

    virtual ~SystemImpl();

    double getValue() const override;

    void setValue(double value) override;

    string getName() const override;

    void setName(string name) override;

    bool operator==(const System &rhs) override;

    bool operator!=(const System &rhs) override;

    System& operator=(const System& rhs) override;
};


#endif //SIMULADOR_SYSTEMIMPL_H
