/*!
* \file FlowBody.h
* Arquivo contendo a Declaração da Classe Abstrata FlowBody
*
* \author Breno Keller
* \since 08/11/18
*/

#ifndef SIMULADOR_FLOWIMPL_H
#define SIMULADOR_FLOWIMPL_H

#include "System.h"
#include "HandleBody.h"

/*!
* \def FLOW
*
* Macro para geração de classe derivadas de flow. Para a criação de equações pode ser utilizado as variáveis source e
* target
*
* \param NAME Nome da classe
* \param EQUATION Equação do fluxo
*/
#define FLOW(NAME, EQUATION) \
   class NAME : public FlowBody { \
       public: \
           NAME() : FlowBody() {} \
           NAME(const string &name) : FlowBody(name) {} \
           NAME(const string &name, System *source, System *target) : FlowBody(name, source, target) {} \
           NAME(const FlowBody &rhs) : FlowBody(rhs) {} \
           virtual ~NAME(){} \
           double execute() override { \
               double source = 0, target = 0; \
               if (this->getSource() != nullptr) { \
                   source = this->getSource()->getValue();\
               }\
               if (this->getTarget() != nullptr) { \
                   target = this->getTarget()->getValue();\
               }\
               return EQUATION; \
           } \
       };

using namespace std;

/*!
* \class FlowBody
* \brief Classe para gerenciar o comportamento de um fluxo utilizando comportamento de um body
*/
class FlowBody : public Body {
private:
    /*!
     * \brief Ponteiro para o sistema de origem
     */
    System *source_;

    /*!
     * \brief Ponteiro para o sistema de destino
     */
    System *target_;

    /*!
     * \brief Nome do fluxo
    */
    string name_;

public:

    /*!
     * \brief Construtor padrão sem parametros
     * \sa FlowBody(const string&), FlowBody(const string&, System*, System*), FlowBody(const FlowBody&)
     */
    FlowBody();

    /*!
     * \brief Construtor padrão de FluxoBody
     * \param name Nome do fluxo
     * \sa FlowBody(const string&, System*, System*), FlowBody(const FlowBody&), FlowBody()
     */
    FlowBody(const string &name);

    /*!
     * \brief Construtor completo de FluxoBody
     * \param name Nome do fluxo
     * \param source Sistema de origem
     * \param target Sistema de destino
     * \sa FlowBody(const string&), FlowBody(const FlowBody&), FlowBody()
     */
    FlowBody(const string &name, System *source, System *target);

    /*!
     * \brief Construtor de cópia de FluxoBody
     * \param rhs Objeto a ser copiado
     * \sa FlowBody(const string&), FlowBody(const string&, System*, System*), FlowBody()
     */
    FlowBody(const FlowBody &rhs);

    /*!
     * \brief Destrutor padrão
     */
    virtual ~FlowBody();

    /*!
     * \brief Método para acessar o sistema de origem
     * \return Ponteiro para o sistema de origem
     */
    System *getSource() const;

    /*!
     * \brief Método para alterar o sistema de origem
     * \param source Novo sistema de origem
     */
    void setSource(System *source);

    /*!
     * \brief Método para acessar o sistema de destino
     * \return Ponteiro para o sistema de destino
     */
    System *getTarget() const;

    /*!
     * \brief Método para alterar o sistema de destino
     * \param target Novo sistema destino
     */
    void setTarget(System *target);

    /*!
     * \brief Método para acessar o nome do fluxo
     * \return Nome do fluxo
     */
    string getName() const;

    /*!
     * \brief Método para acessar o nome do fluxo
     * \param name Novo nome do fluxo
     */
    void setName(string name);

    /*!
     * \brief Método para calcular a equação de iteração entre dois sistemas
     * \return Resultado da equação da fórmula correspondente
     */
    virtual double execute() = 0;

    /*!
     * \brief Método para comparar se dois fluxos são iguais
     * \param rhs Fluxo a ser comparado
     * \return true se igual e false caso contrário
     */
    bool operator==(const FlowBody &rhs);

    /*!
     * \brief Método para comparar se dois fluxos são diferentes
     * \param rhs Fluxo a ser comparado
     * \return true se diferentes e false caso contrário
     */
    bool operator!=(const FlowBody &rhs);

    /*!
     * \brief Operador de atribuição para Flow
     * \param rhs Objeto a ser atribuído
     * \return Referência do objeto atribuído, permitindo encadeamento
     */
    FlowBody &operator=(const FlowBody &rhs);
};


#endif //SIMULADOR_FLOWIMPL_H