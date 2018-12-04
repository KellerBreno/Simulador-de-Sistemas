//
// Created by brenokeller on 11/30/18.
//

#ifndef SIMULADOR_MODELHANDLE_H
#define SIMULADOR_MODELHANDLE_H

#include "Model.h"
#include "ModelImpl.h"
#include "HandleBody.h"

class ModelHandle : public Model, public Handle<ModelImpl> {
protected:
    /*!
     * Modelos gerenciados pela fábrica
     */
    static vector<Model *> models_;

public:
    /*!
     * \brief Método de fábrica para criar modelos informando o nome
     * \param name Nome do modelo a ser criado
     * \return Ponteiro para modelo criado
     * \sa Model::createModel(string)
     */
    static Model *createModel(string name) {
        if (name.empty()) {
            return nullptr;
        }
        Model *m = new ModelHandle(name);
        models_.push_back(m);
        return m;
    }

    /*!
     * \brief Método de fábrica para criar cópia de modelos
     * \param model Ponteiro para o modelo a ser copiado
     * \return Ponteiro para modelo criado
     * \sa Model::createModel(Model*)
     */
    static Model *createModel(Model *model) {
        Model *m = new ModelHandle(model->getName());

        for (Model::systemIterator it = model->beginSystems(); it != model->endSystems(); ++it) {
            m->createSystem((*it)->getName(), (*it)->getValue());
        }

        for (Model::flowIterator it = model->beginFlows(); it != model->endFlows(); ++it) {
            Flow *copy = m->createFlow((*it));
            for (Model::systemIterator itSystem = model->beginSystems(); itSystem != model->endSystems();
                 ++itSystem) {
                if ((copy->getSource() != nullptr) && (copy->getSource()) == ((*itSystem))) {
                    copy->setSource((*itSystem));
                } else if ((copy->getTarget() != nullptr) && (copy->getTarget()) == ((*itSystem))) {
                    copy->setTarget((*itSystem));
                }
            }
        }
        models_.push_back(m);
        return m;
    }

    /*!
     * \brief Método para deletar um modelo
     * \param name Nome do modelo a ser deletado
     * \return verdadeiro caso modelo seja deletado, falso caso contrário ou não exista modelo com esse nome
     * \sa Model::deleteModel(name)
     */
    static bool deleteModel(string name) {
        for (auto it = models_.begin(); it != models_.end(); ++it) {
            ModelHandle *m = dynamic_cast<ModelHandle *>(*it);
            if (m->getName() == name) {
                models_.erase(it);
                delete m;
                return true;
            }
        }
        return false;
    }

    ModelHandle(string name) : Handle() {
        pImpl_->setName(name);
    }

    void simulate(int initialTime, int endTime) override {
        pImpl_->simulate(initialTime, endTime);
    }

    void simulate(int initialTime, int endTime, int step) override {
        pImpl_->simulate(initialTime, endTime, step);
    }

    Flow *getFlow(string name) override {
        return pImpl_->getFlow(name);
    }

    System *getSystem(string name) override {
        return pImpl_->getSystem(name);
    }

    bool deleteFlow(string name) override {
        return pImpl_->deleteFlow(name);
    }

    bool deleteSystem(string name) override {
        return pImpl_->deleteSystem(name);
    }

    string getName() const override {
        return pImpl_->getName();
    }

    void setName(string name) override {
        pImpl_->setName(name);
    }

    string report() override {
        return pImpl_->report();
    }

    System *createSystem(string name) override {
        return pImpl_->createSystem(name);
    }

    System *createSystem(string name, double initValue) override {
        return pImpl_->createSystem(name, initValue);
    }

    System *createSystem(System *system) override {
        return pImpl_->createSystem(system);
    }

    bool operator==(const Model &rhs) override {
        bool resp = this->getName() == rhs.getName();

        bool aux;
        for (Model::systemIterator it = this->beginSystems(); it != this->endSystems(); ++it) {
            aux = false;
            for (Model::systemIterator rhsIt = rhs.beginSystems(); it != rhs.endSystems(); ++it) {
                if ((*it) == (*rhsIt)) {
                    aux = true;
                    continue;
                }
            }
            if (!aux) {
                resp = false;
            }
        }

        for (Model::flowIterator it = this->beginFlows(); it != this->endFlows(); ++it) {
            aux = false;
            for (Model::flowIterator rhsIt = rhs.beginFlows(); it != rhs.endFlows(); ++it) {
                if ((*it) == (*rhsIt)) {
                    aux = true;
                    continue;
                }
            }
            if (!aux) {
                resp = false;
            }
        }

        return resp;
    }

    bool operator!=(const Model &rhs) override {
        return !(operator==(rhs));
    }

    flowIterator beginFlows() const override {
        return pImpl_->beginFlows();
    }

    flowIterator endFlows() const override {
        return pImpl_->endFlows();
    }

    systemIterator beginSystems() const override {
        return pImpl_->beginSystems();
    }

    systemIterator endSystems() const override {
        return pImpl_->endSystems();
    }

protected:
    void add(Flow *f) override {
        pImpl_->add(f);
    }

    void add(System *s) override {
        pImpl_->add(s);
    }
};

vector<Model *> ModelHandle::models_;

Model *Model::createModel(string name) {
    return ModelHandle::createModel(name);
}

Model *Model::createModel(Model *model) {
    return ModelHandle::createModel(model);
}

bool Model::deleteModel(string name) {
    return ModelHandle::deleteModel(name);
}

#endif //SIMULADOR_MODELHANDLE_H
