/*!
* \file ModelImpl.h
* Arquivo contendo a Declaração da Classe ModelImpl
*
* \author Breno Keller
* \since 31/10/18
*/

#ifndef SIMULADOR_MODELIMPL_H
#define SIMULADOR_MODELIMPL_H

#include <vector>
#include "Model.h"

using namespace std;

/*!
* \class ModelImpl
* \brief Classe para gerenciamento de modelos
*/
class ModelImpl : public Model {

private:
    /*!
     * Conjunto de fluxos
     */
    vector<Flow *> flows_;

    /*!
     * Conjunto de sistemas
     */
    vector<System *> systems_;

    /*!
     * Nome do modelo
     */
    string name_;

public:

    // typedef vector<Flow *>::iterator flowIterator;
    // typedef vector<System *>::iterator systemIterator;

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

    /*!
     * \brief Construtor padrão de modelo
     * \param name Nome do modelo
     * \sa ModelImpl(const ModelImpl&)
     */
    ModelImpl(const string &name);

    /*!
     * \brief Construtor de cópia de modelo
     * \param rhs Modelo a ser copiado
     * \sa ModelImpl(const string&)
     */
    ModelImpl(const ModelImpl &rhs);

    /*!
     * \brief Destrutor de modelos, desaloca os elementos alocados pela fábrica
     */
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

    Model &operator=(Model &rhs) override;

    Model::flowIterator beginFlows() override;

    Model::flowIterator endFlows() override;

    Model::systemIterator beginSystems() override;

    Model::systemIterator endSystems() override;

protected:
    void add(Flow *f) override;

    void add(System *s) override;
};


#endif //SIMULADOR_MODELIMPL_H
