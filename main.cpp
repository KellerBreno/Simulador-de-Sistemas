#include "test/TestVensim.h"
#include "test/TestSystem.h"
#include "test/TestFlow.h"
#include "test/TestModel.h"
#include "test/TestHandleBody.h"

int main() {
    TestVensim::run();
    TestSystem::run();
    TestFlow::run();
    TestModel::run();
    TestHandleBody::run();
    return 0;
}