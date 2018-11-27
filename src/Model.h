//
// Created by brenokeller on 10/31/18.
//

#ifndef SIMULADOR_MODEL_H
#define SIMULADOR_MODEL_H

#include <string>
#include <vector>
#include "System.h"
#include "Flow.h"
#include "FlowImpl.h"

// class ModelImpl;

using namespace std;

// TODO especificar iteradores sem forçar tipagem de implementação
class Model {
public:
    // Testes Modelo
    friend class TestModel;

    // Problema: O compilador nao consegue saber que existem os tipos flowIterator e systemIterator somente com a
    // declaração imcompleta de  class ModelImpl
    // typedef ModelImpl::flowIterator flowIterator;
    // typedef ModelImpl::systemIterator systemIterator;

    typedef vector<Flow *>::iterator flowIterator;
    typedef vector<System *>::iterator systemIterator;

    static Model *createModel(string name);

    static Model *createModel(Model *model);

    static bool deleteModel(string name);

    virtual void simulate(int initialTime, int endTime) = 0;

    virtual void simulate(int initialTime, int endTime, int step) = 0;

    virtual Flow *getFlow(string name) = 0;

    virtual System *getSystem(string name) = 0;

    virtual bool deleteFlow(string name) = 0;

    virtual bool deleteSystem(string name) = 0;

    virtual string getName() const = 0;

    virtual void setName(string name) = 0;

    virtual string report() = 0;

    virtual System *createSystem(string name) = 0;

    virtual System *createSystem(string name, double initValue) = 0;

    virtual System *createSystem(System *system) = 0;

    template<typename T_FLOW_IMPL>
    Flow *createFlow(string name, System *s1, System *s2) {
        Flow *flow = new T_FLOW_IMPL(name, s1, s2);
        add(flow);
        return flow;
    };

    template<typename T_FLOW_IMPL>
    Flow *createFlow(string name) {
        return createFlow<T_FLOW_IMPL>(name, nullptr, nullptr);
    };

    Flow *createFlow(Flow *flow) {
        Flow *copy = flow->clone();
        add(copy);
        return copy;
    }

    virtual bool operator==(const Model &rhs) = 0;

    virtual bool operator!=(const Model &rhs) = 0;

    // TODO implementação para const
    virtual Model &operator=(Model &rhs) = 0;

    virtual flowIterator beginFlows() = 0;

    virtual flowIterator endFlows() = 0;

    virtual systemIterator beginSystems() = 0;

    virtual systemIterator endSystems() = 0;

protected:
    virtual void add(Flow *f) = 0;

    virtual void add(System *s) = 0;
};


#endif //SIMULADOR_MODEL_H
