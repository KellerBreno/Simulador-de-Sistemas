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
           NAME(const string &name) : FlowImpl(name) {} \
           NAME(const string &name, System *source, System *target) : FlowImpl(name, source, target) {} \
           NAME(const Flow &rhs) : FlowImpl(rhs) {} \
           virtual ~NAME(){} \
           double execute() override { \
               double source, target; \
               if (this->getSource() == nullptr) { \
                   source = 0; \
               } else {\
                   source = this->getSource()->getValue();\
               }\
               if (this->getTarget() == nullptr) { \
                   target = 0; \
               } else {\
                   target = this->getTarget()->getValue();\
               }\
               return EQUATION; \
           } \
       protected: \
           Flow *clone() override { \
               Flow *flow = new NAME(*this); \
               return flow; \
           } \
       };

using namespace std;

/*!
* \class FlowImpl
* \brief Classe para gerenciar o comportamento de um fluxo
*/
class FlowImpl : public Flow {
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
    FlowImpl(const Flow &rhs);

    /*!
     * \brief Destrutor padrão
     */
    virtual ~FlowImpl();

    System *getSource() const override;

    void setSource(System *source) override;

    System *getTarget() const override;

    void setTarget(System *target) override;

    string getName() const override;

    void setName(string name) override;

    bool operator==(const Flow &rhs) override;

    bool operator!=(const Flow &rhs) override;

    Flow &operator=(const Flow &rhs) override;
};


#endif //SIMULADOR_FLOWIMPL_H