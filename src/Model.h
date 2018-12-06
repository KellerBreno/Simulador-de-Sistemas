/*!
* \file Model.h
* Arquivo contendo a Declaração da Interface Model
*
* \author Breno Keller
* \since 31/10/18
*/

#ifndef SIMULADOR_MODEL_H
#define SIMULADOR_MODEL_H

#include "FlowHandle.h"

/*!
* \class Model
* \brief Interface para gerenciamento de modelos
*/
class Model {
public:
    /*!
     * Classe amiga para testes de Model
     */
    friend class TestModel;

    /*!
     * \brief Método de fábrica para criar modelos informando o nome
     * \param name Nome do modelo a ser criado
     * \return Ponteiro para modelo criado
     * \sa ModelImpl::createModel(string)
     */
    static Model *createModel(string name);

    /*!
     * \brief Método de fábrica para criar cópia de modelos
     * \param model Ponteiro para o modelo a ser copiado
     * \return Ponteiro para modelo criado
     * \sa ModelImpl::createModel(Model*)
     */
    static Model *createModel(Model *model);

    /*!
     * \brief Método para deletar um modelo
     * \param name Nome do modelo a ser deletado
     * \return verdadeiro caso modelo seja deletado, falso caso contrário ou não exista modelo com esse nome
     * \sa ModelImpl::deleteModel(name)
     */
    static bool deleteModel(string name);

    /*!
     * \brief Método para realizar uma simulação
     * \param initialTime Tempo inicial da simulação
     * \param endTime Tempo final da simulação
     * \sa simulate(int,int,int)
     */
    virtual void simulate(int initialTime, int endTime) = 0;

    /*!
     * \brief Método para realizar uma simulação
     * \param initialTime Tempo inicial da simulação
     * \param endTime Tempo final da simulação
     * \param step Passo da simulação
     * \sa simulate(int,int)
     */
    virtual void simulate(int initialTime, int endTime, int step) = 0;

    /*!
     * \brief Método para acessar um fluxo no modelo
     * \param name Nome do fluxo a ser buscado
     * \return Ponteiro para o fluxo caso existe, nullptr caso contrário
     */
    virtual Flow *getFlow(string name) = 0;

    /*!
     * \brief Método para acessar um sistema no modelo
     * \param name Nome do sistema a ser buscado
     * \return Ponteiro para o sistema caso existe, nullptr caso contrário
     */
    virtual System *getSystem(string name) = 0;

    /*!
     * \brief Método para deletar um fluxo
     * \param name Nome do fluxo a ser apagado
     * \return true caso seja deletado, false caso contrário ou nao exista
     */
    virtual bool deleteFlow(string name) = 0;

    /*!
     * \brief Método para deletar um sistema
     * \param name Nome do sistema a ser apagado
     * \return true caso seja deletado, false caso contrário ou nao exista
     */
    virtual bool deleteSystem(string name) = 0;

    /*!
     * \brief Método para acessar o nome do modelo
     * \return Nome do modelo
     */
    virtual string getName() const = 0;

    /*!
     * \brief Método para alterar o nome do modelo
     * \param name Novo nome do modelo
     */
    virtual void setName(string name) = 0;

    /*!
     * \brief Método para gerar um relatório do estado atual da simulação.
     * \return String contendo um relatório da simulação
     */
    virtual string report() = 0;

    /*!
     * \brief Método de fábrica para se criar sistemas pelo nome
     * \param name Nome do sistema a ser criado
     * \return Ponteiro para o sistema criado
     */
    virtual System *createSystem(string name) = 0;

    /*!
     * \brief Método de fábrica para se criar sistemas pelo nome e valor inicial
     * \param name Nome do sistema a ser criado
     * \param initValue Valor inicial
     * \return Ponteiro para o sistema criado
     */
    virtual System *createSystem(string name, double initValue) = 0;

    /*!
     * \brief Método de fábrica para se copiar um sistema
     * \param system Sistema a ser copiado
     * \return Ponteiro para o sistema criado
     */
    virtual System *createSystem(System *system) = 0;

    /*!
     * \brief Método de fábrica para se criar um fluxo pelo nome, origem e destino
     * \tparam T_FLOW_IMPL Tipo de fluxo gerado pelo macro FLOW
     * \param name Nome do fluxo
     * \param s1 Sistema de origem
     * \param s2 Sistema de destino
     * \return Ponteiro para o fluxo criado
     */
    template<typename T_FLOW_IMPL>
    Flow *createFlow(string name, System *s1, System *s2) {
        Flow *flow = new FlowHandle<T_FLOW_IMPL>(name, s1, s2);
        add(flow);
        return flow;
    };

    /*!
     * \brief Método de fábrica para se criar um fluxo pelo nome
     * \tparam T_FLOW_IMPL Tipo de fluxo gerado pelo macro FLOW
     * \param name Nome do fluxo
     * \return Ponteiro para o fluxo criado
     */
    template<typename T_FLOW_IMPL>
    Flow *createFlow(string name) {
        return createFlow<T_FLOW_IMPL>(name, nullptr, nullptr);
    };

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
    virtual bool operator==(const Model &rhs) = 0;

    /*!
     * \brief Método para comparar se dois modelos são diferentes
     * \param rhs Modelo a ser comparado
     * \return true se diferentes e false caso contrário
     */
    virtual bool operator!=(const Model &rhs) = 0;

    /*!
     * \brief Operador de atribuição para Modelo
     * \param rhs Objeto a ser atribuído
     * \return Referência do objeto atribuído, permitindo encadeamento
     */
    virtual Model &operator=(Model &rhs) = 0;

    /*!
     * \brief Metodo para limpar os fluxos
     */
    virtual void clearFlows() = 0;

    /*!
     * \brief Metodo para limpar os sistemas
     */
    virtual void clearSystems() = 0;

    /*!
     * \brief Metodo para posicionar o iterador de Sistemas no inicio
     * \return Verdadeiro caso consiga posicionar o iterador no primeiro elemento
     */
    virtual bool beginSystems() const = 0;

    /*!
     * \brief Metodo para navega no iterador de sistemas em sentido crescente
     * \return Verdadeiro caso consiga passar pra o proximo elemento
     */
    virtual bool nextSystem() const = 0;

    /*!
     * \brief Metodo para acessar o elemento corrente do iterador
     * \return Sistema correspondente a posição do iterador
     */
    virtual System *getCurrentSystem() const = 0;

    /*!
     * \brief Metodo para posicionar o iterador de Fluxos no inicio
     * \return Verdadeiro caso consiga posicionar o iterador no primeiro elemento
     */
    virtual bool beginFlows() const = 0;

    /*!
     * \brief Metodo para navega no iterador de fluxos em sentido crescente
     * \return Verdadeiro caso consiga passar pra o proximo elemento
     */
    virtual bool nextFlow() const = 0;

    /*!
     * \brief Metodo para acessar o elemento corrente do iterador
     * \return Fluxo correspondente a posição do iterador
     */
    virtual Flow *getCurrentFlow() const = 0;

protected:
    /*!
     * \brief Método para adicionar fluxos ao modelo
     * \param f Fluxo a ser adicionado
     */
    virtual void add(Flow *f) = 0;

    /*!
     * \brief Método para adicionar sistemas ao modelo
     * \param s Sistema a ser adicionado
     */
    virtual void add(System *s) = 0;
};


#endif //SIMULADOR_MODEL_H