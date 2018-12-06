/*!
* \file TestHandleBody.cpp
* Arquivo contendo a Implementação da Classe de testes de HandleBody
*
* \author Breno Keller
* \since 04/12/18
*/

#include <iostream>
#include "TestHandleBody.h"

using namespace std;

int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;

void TestHandleBody::run() {
    cout << "=============== Testes HandleBody ===============" << endl;
    TestHandleBody::test();
    cout << "=================================================" << endl;
}

void TestHandleBody::test() {
    cout << "\t\tCriados\t|\tDeletados\t|" << endl;
    cout << "Handle: \t" << numHandleCreated << "\t|\t\t" << numHandleDeleted << "\t|" << endl;
    cout << "Body: \t\t" << numBodyCreated << "\t|\t\t" << numBodyDeleted << "\t|" << endl;
}
