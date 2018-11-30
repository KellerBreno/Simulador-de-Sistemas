/*!
* \file TestVensim.h
* Arquivo contendo a Declaração da Classe de testes funcionais
*
* \author Breno Keller
* \since 6/11/18
*/

#ifndef SIMULADOR_TESTVENSIM_H
#define SIMULADOR_TESTVENSIM_H

/*!
* \class TestVensim
* \brief Classe estruturando os testes funcionais do simulador
*/
class TestVensim {
public:
    /*!
     * \brief Método para executar todos os testes
     */
    static void run();

private:
    /*!
     * \brief Teste de modelo exponencial
     */
    static void modelExp();

    /*!
     * \brief Teste de modelo logístico
     */
    static void modelLog();

    /*!
     * \brief Teste de modelos complexos
     */
    static void modelWithLoop();

//    /*!
//     * \brief Teste de modelos copiados
//     */
//    static void modelCopy();
//
//    /*!
//     * \brief Teste de modelos atribuídos
//     */
//    static void modelAtrib();
};


#endif //SIMULADOR_TESTVENSIM_H