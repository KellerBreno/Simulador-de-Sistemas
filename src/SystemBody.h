/*!
* \file SystemBody.h
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
* \class SystemBody
* \brief Classe para gerenciar o comportamento de um sistema utilizando comportamento de um body
*/
class SystemBody : public Body {

private:
    /*!
     * \brief Nome do sistema
     */
    string name_;

    /*!
     * \brief Valor armazenado no sistema
     */
    double value_;

public:

    /*!
     * \brief Construtor padrão
     * \sa SystemBody(const SystemBody&), SystemBody(const string&, double)
     */
    SystemBody();

    /*!
     * \brief Construtor padrão de sistema
     * \param name Nome do sistema
     * \param value Valor inicial do sistema
     * \sa SystemBody(const SystemBody&), SystemBody()
     */
    SystemBody(const string &name, double value);

    /*!
     * \brief Construtor de cópia de sistema
     * \param rhs Objeto a ser copiado
     * \sa SystemImpl(const string&, double), SystemBody()
     */
    SystemBody(const SystemBody &rhs);

    /*!
     * \brief Destrutor padrão
     */
    virtual ~SystemBody();

    /*!
     * \brief Método para acessar o valor do sistema
     * \return Valor armazenado no sistema
     */
    double getValue() const;

    /*!
     * \brief Método para alterar o valor do sistema
     * \param value Novo valor no sistema
     */
    void setValue(double value);

    /*!
     * \brief Método para acessar o nome do sistema
     * \return Nome do estoque/sistema
     */
    string getName() const;

    /*!
     * \brief Método para alterar o nome do sistema
     * \param name Novo nome do sistema
     */
    void setName(string name);

    /*!
     * \brief Método para comparar se dois sistemas são iguais
     * \param rhs Sistema a ser comparado
     * \return true se igual e false caso contrário
     */
    bool operator==(const SystemBody &rhs);

    /*!
     * \brief Método para comparar se dois sistemas são diferentes
     * \param rhs Sistema a ser comparado
     * \return true se diferente e false caso contrário
     */
    bool operator!=(const SystemBody &rhs);

    /*!
     * \brief Operador de atribuição para SystemImpl
     * \param rhs Objeto a ser atribuído
     * \return Referência do objeto atribuído, permitindo encadeamento
     */
    SystemBody &operator=(const SystemBody &rhs);
};


#endif //SIMULADOR_SYSTEMIMPL_H