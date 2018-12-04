/*!
* \file TestModel.h
* Arquivo contendo a Declaração da Classe de testes de Modelo
*
* \author Breno Keller
* \since 8/11/18
*/

#ifndef SIMULADOR_TESTMODEL_H
#define SIMULADOR_TESTMODEL_H

/*!
* \class TestModel
* \brief Classe estruturando os testes da classe Model
*/
class TestModel {
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

//    /*!
//     * \brief Teste para construtor de cópia
//     */
//    static void unitCopyConstructor();

    /*!
     * \brief Teste para operador de atribuição
     */
    static void unitOperator();

    /*!
     * \brief Teste para Model::simulate()
     */
    static void unitSimulate();

    /*!
     * \brief Teste para Model::add()
     */
    static void unitAdd();

    /*!
     * \brief Teste para Model::getFlow()
     */
    static void unitGetFlow();

    /*!
     * \brief Teste para Model::getSystem()
     */
    static void unitGetSystem();

    /*!
     * \brief Teste para Model::getName()
     */
    static void unitGetName();

    /*!
     * \brief Teste para Model::setName()
     */
    static void unitSetName();

    /*!
     * \brief Teste para Model::report()
     */
    static void unitReport();

    /*!
     * \brief Teste para operadores de igualdade (==) e diferença (!=)
     */
    static void unitEqualDifferent();

    /*!
     * \brief Teste para métodos de fabrica Model::deleteSystem()
     */
    static void unitDeleteSystem();

    /*!
     * \brief Teste para métodos de fabrica Model::deleteFlow()
     */
    static void unitDeleteFlow();

    /*!
     * \brief Teste para métodos de fabrica Model::createSystem()
     */
    static void unitCreateSystem();

    /*!
     * \brief Teste para métodos de fabrica Model::createFlow()
     */
    static void unitCreateFlow();

    /*!
    * \brief Teste para métodos de fabrica Model::createModel(string)
    */
    static void unitCreateModel();

    /*!
    * \brief Teste para métodos de fabrica Model::createModel(Model*)
    */
    static void unitCreateModelCopy();

    /*!
    * \brief Teste para métodos de fabrica Model::deleteModel()
    */
    static void unitDeleteModel();

    /*!
     * \brief Teste para iteradores de Flow
     */
    static void unitFlowIterator();

    /*!
     * \brief Teste pra iteradores de System
     */
    static void unitSystemIterator();

};

#endif //SIMULADOR_TESTMODEL_H