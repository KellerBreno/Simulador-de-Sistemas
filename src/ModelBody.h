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
class ModelBody : public Body {

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

    vector<System *>::iterator itSystem;

    vector<Flow *>::iterator itFlow;

public:

    ModelBody();

    /*!
     * \brief Construtor padrão de modelo
     * \param name Nome do modelo
     * \sa ModelImpl(const ModelImpl&)
     */
    ModelBody(const string &name);

    /*!
     * \brief Construtor de cópia de modelo
     * \param rhs Modelo a ser copiado
     * \sa ModelImpl(const string&)
     */
    ModelBody(const ModelBody &rhs);

    /*!
     * \brief Destrutor de modelos, desaloca os elementos alocados pela fábrica
     */
    virtual ~ModelBody();

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

    bool operator==(const ModelBody &rhs);

    bool operator!=(const ModelBody &rhs);

    ModelBody &operator=(ModelBody &rhs);

    void clearFlows();

    void clearSystems();

    bool beginSystems();

    bool nextSystem();

    System *getCurrentSystem();

    bool beginFlows();

    bool nextFlow();

    Flow *getCurrentFlow();

    void add(Flow *f);

    void add(System *s);
};


#endif //SIMULADOR_MODELIMPL_H
