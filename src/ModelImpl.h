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
    vector<Flow *> flows_;
    vector<System *> systems_;
    string name_;

public:

    typedef vector<Flow *>::iterator flowIterator;
    typedef vector<System *>::iterator systemIterator;

    static Model *createModel(string name);

    static Model *createModel(Model *model);

    static bool deleteModel(string name);

    ModelImpl(const string &name);

    ModelImpl(const ModelImpl &rhs);

    virtual ~ModelImpl();

    void simulate(int initialTime, int endTime) override;

    void simulate(int initialTime, int endTime, int step) override;

    Flow *getFlow(string name) override;

    System *getSystem(string name) override;

    bool deleteFlow(string name) override;

    bool deleteSystem(string name) override;

    string getName() const override;

    void setName(string name) override;

    string report() override;

    System *createSystem(string name) override;

    System *createSystem(string name, double initValue) override;

    System *createSystem(System *system) override;

    bool operator==(const Model &rhs) override;

    bool operator!=(const Model &rhs) override;

    // Model &operator=(const Model &rhs) override;

    // flowIterator beginFlows() override;

    // flowIterator endFlows() override;

    // systemIterator beginSystems() override;

    // systemIterator endSystems() override;

protected:
    void add(Flow *f) override;

    void add(System *s) override;
};


#endif //SIMULADOR_MODELIMPL_H
