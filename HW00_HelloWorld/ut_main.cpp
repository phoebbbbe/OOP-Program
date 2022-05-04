#include <gtest/gtest.h>
#include "Hello.hpp"

TEST(HELLO, PrintHello)
{
    string output = PrintHello();
    string compare = "Hello! \n";
    ASSERT_EQ(output, compare);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}