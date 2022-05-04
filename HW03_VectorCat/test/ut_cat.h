#include "../src/cat.h"

#include <gtest/gtest.h>

// add your test here
TEST(Cat, GetName1)
{
    std::string name1 = "Kitty";
    std::string name2 = "Cathy";
    double weight = 10;
    Cat myCat1(name1, weight);
    Cat myCat2(name2, weight);
    ASSERT_EQ(myCat1.getName(), "Kitty");
    ASSERT_EQ(myCat2.getName(), "Cathy");
}

TEST(Cat, GetName2)
{
    std::string name1 = "John";
    std::string name2 = "Paul";
    double weight = 10.5;
    Cat myCat1(name1, weight);
    Cat myCat2(name2, weight);
    ASSERT_EQ(myCat1.getName(), "John");
    ASSERT_EQ(myCat2.getName(), "Paul");
}

TEST(Cat, GetWeight1)
{
    std::string name = "Kitty";
    double weight1 = 10.5;
    double weight2 = 22.2;
    Cat myCat1(name, weight1);
    Cat myCat2(name, weight2);
    ASSERT_NEAR(myCat1.getWeight(), 10.5, 0.001);
    ASSERT_NEAR(myCat2.getWeight(), 22.2, 0.001);
}

TEST(Cat, GetWeight2)
{
    std::string name = "John";
    double weight1 = 20;
    double weight2 = 30;
    Cat myCat1(name, weight1);
    Cat myCat2(name, weight2);
    ASSERT_NEAR(myCat1.getWeight(), 20, 0.001);
    ASSERT_NEAR(myCat2.getWeight(), 30, 0.001);
}

TEST(Cat, AddNewToy1)
{
    std::string name = "Kitty";
    double weight = 10;
    Cat myCat(name, weight);
    myCat.addNewToy("toy1");
    myCat.addNewToy("toy2");
    myCat.addNewToy("toy3");
    ASSERT_EQ(myCat.getAmount(), 3);
}

TEST(Cat, AddNewToy2)
{
    std::string name = "John";
    double weight = 22.2;
    Cat myCat(name, weight);
    myCat.addNewToy("toy1");
    myCat.addNewToy("toy2");
    myCat.addNewToy("toy3");
    myCat.addNewToy("toy4");
    myCat.addNewToy("toy5");
    myCat.addNewToy("toy6");
    myCat.addNewToy("toy7");
    myCat.addNewToy("toy8");
    myCat.addNewToy("toy9");
    myCat.addNewToy("toy10");
    ASSERT_EQ(myCat.getAmount(), 10);
}

TEST(Cat, getToy1)
{
    std::string name = "Kitty";
    double weight = 10;
    Cat myCat(name, weight);
    myCat.addNewToy("toy1");
    myCat.addNewToy("toy2");
    myCat.addNewToy("toy3");
    myCat.addNewToy("toy4");
    ASSERT_EQ(myCat.getToy(0), "toy1");
    ASSERT_EQ(myCat.getToy(1), "toy2");
    ASSERT_EQ(myCat.getToy(2), "toy3");
    ASSERT_EQ(myCat.getToy(3), "toy4");
}
TEST(Cat, getToy2)
{
    std::string name = "Lucky";
    double weight = 25;
    Cat myCat(name, weight);
    myCat.addNewToy("toy1");
    myCat.addNewToy("toy2");
    myCat.addNewToy("toy3");
    myCat.addNewToy("toy4");
    myCat.addNewToy("toy5");
    myCat.addNewToy("toy6");
    myCat.addNewToy("toy7");
    myCat.addNewToy("toy8");
    myCat.addNewToy("toy9");
    myCat.addNewToy("toy10");
    ASSERT_EQ(myCat.getToy(0), "toy1");
    ASSERT_EQ(myCat.getToy(1), "toy2");
    ASSERT_EQ(myCat.getToy(2), "toy3");
    ASSERT_EQ(myCat.getToy(3), "toy4");
    ASSERT_EQ(myCat.getToy(4), "toy5");
    ASSERT_EQ(myCat.getToy(5), "toy6");
    ASSERT_EQ(myCat.getToy(6), "toy7");
    ASSERT_EQ(myCat.getToy(7), "toy8");
    ASSERT_EQ(myCat.getToy(8), "toy9");
    ASSERT_EQ(myCat.getToy(9), "toy10");
}

