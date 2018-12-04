//
// Created by brenokeller on 11/30/18.
//

#ifndef SIMULADOR_MODELHANDLE_H
#define SIMULADOR_MODELHANDLE_H

#include "Model.h"
#include "ModelBody.h"
#include "HandleBody.h"

class ModelHandle : public Model, public Handle<ModelBody> {
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
    static Model *createModel(string name);

    /*!
     * \brief Método de fábrica para criar cópia de modelos
     * \param model Ponteiro para o modelo a ser copiado
     * \return Ponteiro para modelo criado
     * \sa Model::createModel(Model*)
     */
    static Model *createModel(Model *model);

    /*!
     * \brief Método para deletar um modelo
     * \param name Nome do modelo a ser deletado
     * \return verdadeiro caso modelo seja deletado, falso caso contrário ou não exista modelo com esse nome
     * \sa Model::deleteModel(name)
     */
    static bool deleteModel(string name);

    ModelHandle(string name);

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

    Model &operator=(Model &rhs) override;

    flowIterator beginFlows() const override;

    flowIterator endFlows() const override;

    void clearFlows() override;

    systemIterator beginSystems() const override;

    systemIterator endSystems() const override;

    void clearSystems() override;

protected:
    void add(Flow *f) override;

    void add(System *s) override;
};

#endif //SIMULADOR_MODELHANDLE_H
