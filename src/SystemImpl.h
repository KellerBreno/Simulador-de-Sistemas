//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_SYSTEMIMPL_H
#define SIMULADOR_SYSTEMIMPL_H

#include "System.h"

using namespace std;

class SystemImpl : public System {

private:
    string name;
    double value{};

public:
    SystemImpl(const string &name, double value);

    SystemImpl(const SystemImpl &rhs);

    virtual ~SystemImpl();

    double getValue() const override;

    void setValue(double value) override;

    string getName() const override;

    void setName(string name) override;

    SystemImpl &operator=(const SystemImpl &rhs);

    bool operator==(const System& rhs) override;
};


#endif //SIMULADOR_SYSTEMIMPL_H
