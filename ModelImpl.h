//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_MODELIMPL_H
#define SIMULADOR_MODELIMPL_H

#include <vector>
#include "Model.h"

using namespace std;

class ModelImpl : public Model {

private:
    vector<Flow *> flows;
    vector<System *> systems;
    string name;

public:
    ModelImpl(const string &name);

    virtual ~ModelImpl();

    void simulate(int initialTime, int endTime) override;

    void simulate(int initialTime, int endTime, int step) override;

    void add(Flow *f) override;

    void add(System *s) override;

    Flow *getFlow(string name) override;

    System *getSystem(string name) override;

    bool remove(string name) override;

    string getName() override;

    void setName(string name) override;

    Flow *getFlows() override;

    System *getSystems() override;

    string report() override;
};


#endif //SIMULADOR_MODELIMPL_H
