/*!
* \file TestFlow.h
* Arquivo contendo a Declaração da Classe de testes de Fluxo
*
* \author Breno Keller
* \since 8/11/18
*/

#ifndef SIMULADOR_TESTFLOW_H
#define SIMULADOR_TESTFLOW_H

/*!
* \class TestFlow
* \brief Classe estruturando os testes da classe Flow
*/
class TestFlow {
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
     * \brief Teste para Flow::execute()
     */
    static void unitExecute();

    /*!
     * \brief Teste para Flow::execute()
     */
    static void unitGetSource();

    /*!
     * \brief Teste para Flow::execute()
     */
    static void unitSetSource();

    /*!
     * \brief Teste para Flow::execute()
     */
    static void unitGetTarget();

    /*!
     * \brief Teste para Flow::execute()
     */
    static void unitSetTarget();

    /*!
     * \brief Teste para Flow::execute()
     */
    static void unitGetName();

    /*!
     * \brief Teste para Flow::execute()
     */
    static void unitSetName();

    /*!
     * \brief Teste para operadores de igualdade (==) e diferença (!=)
     */
    static void unitEqualDifferent();

    /*!
     * \brief Teste para Flow::clone()
     */
    static void unitClone();
};

#endif //SIMULADOR_TESTFLOW_H
