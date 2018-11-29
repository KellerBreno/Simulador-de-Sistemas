/*!
* \file TestSystem.h
* Arquivo contendo a Declaração da Classe de testes de Sistema
*
* \author Breno Keller
* \since 6/11/18
*/

#ifndef SIMULADOR_TESTSYSTEM_H
#define SIMULADOR_TESTSYSTEM_H

/*!
* \class TestSystem
* \brief Classe estruturando os testes da classe System
*/
class TestSystem {
public:
    /*!
    * \brief Método para executar todos os testes
    */
    static void run();

private:
    /*!
     * \brief Teste para construtor
     */
    static void unitConstructor();

    /*!
     * \brief Teste para construtor de cópia
     */
//    static void unitCopyConstructor();

    /*!
     * \brief Teste para operador de atribuição
     */
    static void unitOperator();

    /*!
     * \brief Teste para System::getValue()
     */
    static void unitGetValue();

    /*!
     * \brief Teste para System::setValue(double)
     */
    static void unitSetValue();

    /*!
     * \brief Teste para System::getName()
     */
    static void unitGetName();

    /*!
     * \brief Teste para System::setValue(const name&)
     */
    static void unitSetName();

    /*!
     * \brief Teste para operadores de igualdade (==) e diferença (!=)
     */
    static void unitEqualDifferent();
};


#endif //SIMULADOR_TESTSYSTEM_H