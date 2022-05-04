#include "../src/toy.h"
#include <gtest/gtest.h>

TEST(Toy, GetName)
{
    std::string name = "Ball";
    Toy myToy(name);
    ASSERT_EQ(myToy.getName(), "Ball");
}

TEST(Toy, GetName2)
{
    std::string name = "Candy";
    Toy myToy(name);
    ASSERT_EQ(myToy.getName(), "Candy");
}