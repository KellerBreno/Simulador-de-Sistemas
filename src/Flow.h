/*!
* \file Flow.h
* Arquivo contendo a Declaração da Interface Flow
*
* \author Breno Keller
* \since 31/10/18
*/

#ifndef SIMULADOR_FLOW_H
#define SIMULADOR_FLOW_H

#include "System.h"

using namespace std;

/*!
* \class Flow
* \brief Interface para gerenciar o comportamento de um fluxo
*/
class Flow {
public:
    /*!
     * Acesso como amiga para operações de cópia em Model
     */
    friend class Model;

    /*!
     * Acesso como amiga para operações de cópia em ModelBody
     */
    friend class ModelBody;

    /*!
     * Classe amiga para testes de Flow
    */
    friend class TestFlow;

    /*!
     * \brief Método para calcular a equação de iteração entre dois sistemas
     * \return Resultado da equação da fórmula correspondente
     */
    virtual double execute() = 0;

    /*!
     * \brief Método para acessar o sistema de origem
     * \return Ponteiro para o sistema de origem
     */
    virtual System *getSource() const = 0;

    /*!
     * \brief Método para alterar o sistema de origem
     * \param source Novo sistema de origem
     */
    virtual void setSource(System *source) = 0;

    /*!
     * \brief Método para acessar o sistema de destino
     * \return Ponteiro para o sistema de destino
     */
    virtual System *getTarget() const = 0;

    /*!
     * \brief Método para alterar o sistema de destino
     * \param target Novo sistema destino
     */
    virtual void setTarget(System *target) = 0;

    /*!
     * \brief Método para acessar o nome do fluxo
     * \return Nome do fluxo
     */
    virtual string getName() const = 0;

    /*!
     * \brief Método para acessar o nome do fluxo
     * \param name Novo nome do fluxo
     */
    virtual void setName(string name) = 0;

    /*!
     * \brief Método para comparar se dois fluxos são iguais
     * \param rhs Fluxo a ser comparado
     * \return true se igual e false caso contrário
     */
    virtual bool operator==(const Flow &rhs) = 0;

    /*!
     * \brief Método para comparar se dois fluxos são diferentes
     * \param rhs Fluxo a ser comparado
     * \return true se diferentes e false caso contrário
     */
    virtual bool operator!=(const Flow &rhs) = 0;

protected:
    /*!
     * \brief Método para se gerar uma cópia de fluxo
     * \return Cópia de um fluxo
     */
    virtual Flow *clone() = 0;

};


#endif //SIMULADOR_FLOW_H