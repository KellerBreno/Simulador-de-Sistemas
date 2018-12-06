/*!
* \file SystemHandle.h
* Arquivo contendo a Declaração da Classe SystemHandle
*
* \author Breno Keller
* \since 29/11/18
*/

#ifndef SIMULADOR_SYSTEMHANDLE_H
#define SIMULADOR_SYSTEMHANDLE_H

#include "System.h"
#include "SystemBody.h"

/*!
 * \class SystemHandle
 * \brief Handle para Sistemas
 */
class SystemHandle : public System, public Handle<SystemBody> {
public:
    /*!
     * \brief Construtor base de SystemHandle
     * \param name Nome do sistema
     * \param value Valor inicial do sistema
     */
    SystemHandle(string name, double value);

    /*!
     * \brief Destrutor padrão
     */
    virtual ~SystemHandle();

    double getValue() const override;

    void setValue(double value) override;

    string getName() const override;

    void setName(string name) override;

    bool operator==(const System &rhs) override;

    bool operator!=(const System &rhs) override;
};


#endif //SIMULADOR_SYSTEMHANDLE_H