/*!
* \file System.h
* Arquivo contendo a Declaração da Interface System
*
* \author Breno Keller
* \since 31/10/18
*/

#ifndef SIMULADOR_SYSTEM_H
#define SIMULADOR_SYSTEM_H

#include <string>

using namespace std;

/*!
* \class System
* \brief Interface para gerenciar o comportamento de um sistema
*/
class System {
public:
    /*!
     * Classe amiga para testes de System
     */
    friend class TestSystem;

    /*!
     * \brief Método para acessar o valor do sistema
     * \return Valor armazenado no sistema
     */
    virtual double getValue() const = 0;

    /*!
     * \brief Método para alterar o valor do sistema
     */
    virtual void setValue(double value) = 0;

    /*!
     * \brief Método para acessar o nome do sistema
     * \return Nome do estoque/sistema
     */
    virtual string getName() const = 0;

    /*!
     * \brief Método para alterar o nome do sistema
     */
    virtual void setName(string name) = 0;

    /*!
     * \brief Método para comparar se dois sistemas são iguais
     * \param rhs Sistema a ser comparado
     * \return true se igual e false caso contrário
     */
    virtual bool operator==(const System &rhs) = 0;

    /*!
     * \brief Método para comparar se dois sistemas são diferentes
     * \param rhs Sistema a ser comparado
     * \return true se diferente e false caso contrário
     */
    virtual bool operator!=(const System &rhs) = 0;
};


#endif //SIMULADOR_SYSTEM_H