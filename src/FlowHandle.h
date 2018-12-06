/*!
* \file FlowHandle.h
* Arquivo contendo a Declaração e Implementação da Classe FlowHandle
*
* \author Breno Keller
* \since 30/11/18
*/

#ifndef SIMULADOR_FLOWHANDLE_H
#define SIMULADOR_FLOWHANDLE_H

#include "Flow.h"
#include "FlowBody.h"

/*!
 * \class FlowHandle
 * \brief Classe Handle para fluxos
 * \tparam T_FLOW_IMPL Classe derivada FlowBody
 */
template<class T_FLOW_IMPL>
class FlowHandle : public Flow, public Handle<T_FLOW_IMPL> {
public:
    /*!
     * \brief Construtor basico
     * \param name Nome do Fluxo
     */
    FlowHandle(const string &name) : Handle<T_FLOW_IMPL>() {
        this->pImpl_->setName(name);
    }

    /*!
     * \brief Construtor completo
     * \param name Nome do fluxo
     * \param source Sistema origem
     * \param target Sistema destino
     */
    FlowHandle(const string &name, System *source, System *target) : Handle<T_FLOW_IMPL>() {
        this->pImpl_->setName(name);
        this->pImpl_->setSource(source);
        this->pImpl_->setTarget(target);
    }

    /*!
     * \brief Destrutor padrão
     */
    virtual ~FlowHandle() {

    }

    double execute() override {
        return this->pImpl_->execute();
    }

    System *getSource() const override {
        return this->pImpl_->getSource();
    }

    void setSource(System *source) override {
        this->pImpl_->setSource(source);
    }

    System *getTarget() const override {
        return this->pImpl_->getTarget();
    }

    void setTarget(System *target) override {
        this->pImpl_->setTarget(target);
    }

    string getName() const override {
        return this->pImpl_->getName();
    }

    void setName(string name) override {
        this->pImpl_->setName(name);
    }

    bool operator==(const Flow &rhs) override {
        bool resp = this->getName() == rhs.getName();

        resp = resp && (this->getSource() == rhs.getSource());
        resp = resp && (this->getTarget() == rhs.getTarget());

        return resp;
    }

    bool operator!=(const Flow &rhs) override {
        return !(operator==(rhs));
    }

protected:
    Flow *clone() override {
        Flow *f = new FlowHandle<T_FLOW_IMPL>(this->getName(), this->getSource(), this->getTarget());
        return f;
    }
};


#endif //SIMULADOR_FLOWHANDLE_H
