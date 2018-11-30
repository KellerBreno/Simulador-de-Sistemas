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
#include "HandleBody.h"
#include "Flow.h"
#include "Model.h"

using namespace std;

/*!
* \class ModelImpl
* \brief Classe para gerenciamento de modelos
*/
class ModelImpl : public Body {

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

    ModelImpl();

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

    void simulate(int initialTime, int endTime);

    void simulate(int initialTime, int endTime, int step);

    Flow *getFlow(string name);

    System *getSystem(string name);

    bool deleteFlow(string name);

    bool deleteSystem(string name);

    string getName() const;

    void setName(string name);

    string report();

    System *createSystem(string name);

    System *createSystem(string name, double initValue);

    System *createSystem(System *system);

    Flow *createFlow(Flow *flow) {
        Flow *copy = flow->clone();
        add(copy);
        return copy;
    }

    bool operator==(const ModelImpl &rhs);

    bool operator!=(const ModelImpl &rhs);

    ModelImpl &operator=(ModelImpl &rhs);

    Model::flowIterator beginFlows();

    Model::flowIterator endFlows();

    Model::systemIterator beginSystems();

    Model::systemIterator endSystems();

    void add(Flow *f);

    void add(System *s);
};


#endif //SIMULADOR_MODELIMPL_H
