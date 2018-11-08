#include "test/TestVensim.h"
#include "test/TestSystem.h"
#include "test/TestFlow.h"
#include "test/TestModel.h"

int main() {
    TestVensim::run();
    TestSystem::run();
    TestFlow::run();
    TestModel::run();
    return 0;
}