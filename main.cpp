#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char* argv[]) {
    std::cout << "Data Structures!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}