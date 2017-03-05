#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char* argv[]) {
    std::cout << "Data Structures!" << std::endl;
    // this is how to run a single test!!
    //::testing::GTEST_FLAG(filter) = "classTestPrefixTree.test1";
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}