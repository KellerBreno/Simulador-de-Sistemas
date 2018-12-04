/*!
* \file FlowImpl.h
* Arquivo contendo a Declaração da Classe Abstrata FlowImpl
*
* \author Breno Keller
* \since 08/11/18
*/

#ifndef SIMULADOR_FLOWIMPL_H
#define SIMULADOR_FLOWIMPL_H

#include "Flow.h"
#include "HandleBody.h"

// TODO operadores aritmeticos para system
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
   class NAME : public FlowImpl { \
       public: \
           NAME() : FlowImpl() {} \
           NAME(const string &name) : FlowImpl(name) {} \
           NAME(const string &name, System *source, System *target) : FlowImpl(name, source, target) {} \
           NAME(const FlowImpl &rhs) : FlowImpl(rhs) {} \
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
* \class FlowImpl
* \brief Classe para gerenciar o comportamento de um fluxo
*/
class FlowImpl : public Body {
private:
    /*!
     * Ponteiro para o sistema de origem
     */
    System *source_;

    /*!
     * Ponteiro para o sistema de destino
     */
    System *target_;

    /*!
     * Nome do fluxo
    */
    string name_;

public:

    FlowImpl();

    /*!
     * \brief Construtor padrão de fluxo
     * \param name Nome do fluxo
     * \sa FlowImpl(const string&, System*, System*), FlowImpl(const Flow&)
     */
    FlowImpl(const string &name);

    /*!
     * \brief Construtor completo de fluxo
     * \param name Nome do fluxo
     * \param source Sistema de Origem
     * \param target Sistema de Destino
     * \sa FlowImpl(const string&), FlowImpl(const Flow&)
     */
    FlowImpl(const string &name, System *source, System *target);

    /*!
     * \brief Construtor de cópia de fluxo
     * \param rhs Objeto a ser copiado
     * \sa FlowImpl(const string&), FlowImpl(const string&, System*, System*)
     */
    FlowImpl(const FlowImpl &rhs);

    /*!
     * \brief Destrutor padrão
     */
    virtual ~FlowImpl();

    System *getSource() const;

    void setSource(System *source);

    System *getTarget() const;

    void setTarget(System *target);

    string getName() const;

    void setName(string name);

    virtual double execute() = 0;

    bool operator==(const FlowImpl &rhs);

    bool operator!=(const FlowImpl &rhs);

    FlowImpl &operator=(const FlowImpl &rhs);
};


#endif //SIMULADOR_FLOWIMPL_H