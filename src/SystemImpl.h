/*!
* \file SystemImpl.h
* Arquivo contendo a Declaração da Classe SystemImpl
*
* \author Breno Keller
* \since 31/10/18
*/

#ifndef SIMULADOR_SYSTEMIMPL_H
#define SIMULADOR_SYSTEMIMPL_H

#include "HandleBody.h"
#include <string>

using namespace std;

/*!
* \class SystemImpl
* \brief Classe para gerenciar o comportamento de um sistema
*/
class SystemImpl : public Body {

private:
    /*!
     * Nome do sistema
     */
    string name_;

    /*!
     * Valor armazenado no sistema
     */
    double value_;

public:

    SystemImpl();

    /*!
     * \brief Construtor padrão de sistema
     * \param name Nome do sistema
     * \param value Valor inicial do sistema
     * \sa SystemImpl(const System&)
     */
    SystemImpl(const string &name, double value);

    /*!
     * \brief Construtor de cópia de sistema
     * \param rhs Objeto a ser copiado
     * \sa SystemImpl(const string&, double)
     */
    SystemImpl(const SystemImpl &rhs);

    /*!
     * \brief Destrutor padrão
     */
    virtual ~SystemImpl();

    double getValue() const;

    void setValue(double value);

    string getName() const;

    void setName(string name);

    bool operator==(const SystemImpl &rhs);

    bool operator!=(const SystemImpl &rhs);

    /*!
     * \brief Operador de atribuição para SystemImpl
     * \param rhs Objeto a ser atribuído
     * \return Referência do objeto atribuído, permitindo encadeamento
     */
    SystemImpl &operator=(const SystemImpl &rhs);
};


#endif //SIMULADOR_SYSTEMIMPL_H