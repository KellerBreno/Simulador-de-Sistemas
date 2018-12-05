//
// Created by brenokeller on 12/4/18.
//

#include "TestHandleBody.h"
#include "../src/Model.h"
#include <iostream>
#include <cassert>

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
