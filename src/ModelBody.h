/*!
* \file ModelBody.h
* Arquivo contendo a Declaração da Classe ModelBody
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
     * \brief Conjunto de fluxos
     */
    vector<Flow *> flows_;

    /*!
     * \brief Conjunto de sistemas
     */
    vector<System *> systems_;

    /*!
     * \brief Nome do modelo
     */
    string name_;

    /*!
     * \brief Iterador de sistemas
     */
    vector<System *>::iterator itSystem;

    /*!
     * \brief Iterador de fluxos
     */
    vector<Flow *>::iterator itFlow;

public:

    /*!
     * \brief Construtor padrão
     * \sa ModelBody(const ModelBody&), ModelBody(const string&)
     */
    ModelBody();

    /*!
     * \brief Construtor padrão de modelo
     * \param name Nome do modelo
     * \sa ModelBody(const ModelImpl&), ModelBody()
     */
    ModelBody(const string &name);

    /*!
     * \brief Construtor de cópia de modelo
     * \param rhs Modelo a ser copiado
     * \sa ModelImpl(const string&), ModelBody()
     */
    ModelBody(const ModelBody &rhs);

    /*!
     * \brief Destrutor de modelos, desaloca os elementos alocados pela fábrica
     */
    virtual ~ModelBody();

    /*!
     * \brief Método para realizar uma simulação
     * \param initialTime Tempo inicial da simulação
     * \param endTime Tempo final da simulação
     * \sa simulate(int,int,int)
     */
    void simulate(int initialTime, int endTime);

    /*!
     * \brief Método para realizar uma simulação
     * \param initialTime Tempo inicial da simulação
     * \param endTime Tempo final da simulação
     * \param step Passo da simulação
     * \sa simulate(int,int)
     */
    void simulate(int initialTime, int endTime, int step);

    /*!
     * \brief Método para acessar um fluxo no modelo
     * \param name Nome do fluxo a ser buscado
     * \return Ponteiro para o fluxo caso existe, nullptr caso contrário
     */
    Flow *getFlow(string name);

    /*!
     * \brief Método para acessar um sistema no modelo
     * \param name Nome do sistema a ser buscado
     * \return Ponteiro para o sistema caso existe, nullptr caso contrário
     */
    System *getSystem(string name);

    /*!
     * \brief Método para deletar um fluxo
     * \param name Nome do fluxo a ser apagado
     * \return true caso seja deletado, false caso contrário ou nao exista
     */
    bool deleteFlow(string name);

    /*!
     * \brief Método para deletar um sistema
     * \param name Nome do sistema a ser apagado
     * \return true caso seja deletado, false caso contrário ou nao exista
     */
    bool deleteSystem(string name);

    /*!
     * \brief Método para acessar o nome do modelo
     * \return Nome do modelo
     */
    string getName() const;

    /*!
     * \brief Método para alterar o nome do modelo
     * \param name Novo nome do modelo
     */
    void setName(string name);

    /*!
     * \brief Método para gerar um relatório do estado atual da simulação.
     * \return String contendo um relatório da simulação
     */
    string report();

    /*!
     * \brief Método de fábrica para se criar sistemas pelo nome
     * \param name Nome do sistema a ser criado
     * \return Ponteiro para o sistema criado
     */
    System *createSystem(string name);

    /*!
     * \brief Método de fábrica para se criar sistemas pelo nome e valor inicial
     * \param name Nome do sistema a ser criado
     * \param initValue Valor inicial
     * \return Ponteiro para o sistema criado
     */
    System *createSystem(string name, double initValue);

    /*!
     * \brief Método de fábrica para se copiar um sistema
     * \param system Sistema a ser copiado
     * \return Ponteiro para o sistema criado
     */
    System *createSystem(System *system);

    /*!
     * \brief Método de fábrica para se copiar um fluxo
     * \param flow Flow a ser copiado
     * \return Ponteiro para o fluxo criado
     */
    Flow *createFlow(Flow *flow) {
        Flow *copy = flow->clone();
        add(copy);
        return copy;
    }

    /*!
     * \brief Método para comparar se dois modelos são iguais
     * \param rhs Modelo a ser comparado
     * \return true se igual e false caso contrário
     */
    bool operator==(const ModelBody &rhs);

    /*!
     * \brief Método para comparar se dois modelos são diferentes
     * \param rhs Modelo a ser comparado
     * \return true se diferentes e false caso contrário
     */
    bool operator!=(const ModelBody &rhs);

    /*!
     * \brief Operador de atribuição para Modelo
     * \param rhs Objeto a ser atribuído
     * \return Referência do objeto atribuído, permitindo encadeamento
     */
    ModelBody &operator=(ModelBody &rhs);

    /*!
     * \brief Metodo para limpar os fluxos
     */
    void clearFlows();

    /*!
     * \brief Metodo para limpar os sistemas
     */
    void clearSystems();

    /*!
     * \brief Metodo para posicionar o iterador de Sistemas no inicio
     * \return Verdadeiro caso consiga posicionar o iterador no primeiro elemento
     */
    bool beginSystems();

    /*!
     * \brief Metodo para navega no iterador de sistemas em sentido crescente
     * \return Verdadeiro caso consiga passar pra o proximo elemento
     */
    bool nextSystem();

    /*!
     * \brief Metodo para acessar o elemento corrente do iterador
     * \return Sistema correspondente a posição do iterador
     */
    System *getCurrentSystem();

    /*!
     * \brief Metodo para posicionar o iterador de Fluxos no inicio
     * \return Verdadeiro caso consiga posicionar o iterador no primeiro elemento
     */
    bool beginFlows();


    /*!
     * \brief Metodo para navega no iterador de fluxos em sentido crescente
     * \return Verdadeiro caso consiga passar pra o proximo elemento
     */
    bool nextFlow();

    /*!
     * \brief Metodo para acessar o elemento corrente do iterador
     * \return Fluxo correspondente a posição do iterador
     */
    Flow *getCurrentFlow();

    /*!
     * \brief Método para adicionar fluxos ao modelo
     * \param f Fluxo a ser adicionado
     */
    void add(Flow *f);

    /*!
     * \brief Método para adicionar sistemas ao modelo
     * \param s Sistema a ser adicionado
     */
    void add(System *s);
};


#endif //SIMULADOR_MODELIMPL_H
