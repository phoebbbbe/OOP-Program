#include "../src/cat.h"

#include <gtest/gtest.h>

TEST(Cat, Constructor)
{
    std::string name = "";
    double weight = 25;
    //Cat myCat(name, weight);
    ASSERT_THROW(Cat myCat(name, weight), std::string);
}

TEST(Cat, Constructor2)
{
    std::string name = "Kitty";
    double weight1 = 5;
    double weight2 = 55;
    ASSERT_THROW(Cat myCat1(name, weight1), std::string);
    ASSERT_THROW(Cat myCat2(name, weight2), std::string);
}

TEST(Cat, CopyConstructor)
{
    std::string name = "Kitty";
    double weight = 25;
    Cat cat1(name, weight);
    Cat cat2 = cat1;
    ASSERT_EQ(cat2.getName(), "Kitty");
    ASSERT_NEAR(cat2.getWeight(), 25, 0.001);
}

TEST(Cat, CopyConstructor2)
{
    std::string name = "John";
    double weight = 33;
    Cat cat1(name, weight);
    Cat cat2 = cat1;
    ASSERT_EQ(cat2.getName(), "John");
    ASSERT_NEAR(cat2.getWeight(), 33, 0.001);
}
TEST(Cat, OperatorEqual)
{
    std::string name1 = "Kitty";
    std::string name2 = "John";
    double weight1 = 22;
    double weight2 = 30;
    Cat cat1(name1, weight1);
    Cat cat2(name2, weight2);
    cat1 = cat2;
    ASSERT_EQ(cat1.getName(), "John");
    ASSERT_NEAR(cat1.getWeight(), 30, 0.001);
}

TEST(Cat, OperatorEqual2)
{
    std::string name1 = "Jenny";
    std::string name2 = "Hanson";
    double weight1 = 25;
    double weight2 = 33;
    Cat cat1(name1, weight1);
    Cat cat2(name2, weight2);
    cat1 = cat2;
    ASSERT_EQ(cat1.getName(), "Hanson");
    ASSERT_NEAR(cat1.getWeight(), 33, 0.001);
}

/* TEST(Cat, GetName1)
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
*/

TEST(Cat, AddNewToy1)
{
    std::string name = "Kitty";
    double weight = 25;
    Cat cat(name, weight);

    std::string toyname1 = "toy1";
    std::string toyname2 = "toy2";
    Toy toy1(toyname1);
    Toy toy2(toyname2);
    cat.addNewToy(toy1);
    cat.addNewToy(toy2);
    ASSERT_EQ(cat.getAmount(), 2);
}

TEST(Cat, AddNewToy2)
{
    std::string name = "Kitty";
    double weight = 25;
    Cat cat(name, weight);

    std::string toyname1 = "toy1";
    std::string toyname2 = "toy2";
    std::string toyname3 = "toy3";
    std::string toyname4 = "toy4";
    std::string toyname5 = "toy5";
    std::string toyname6 = "toy6";
    Toy toy1(toyname1);
    Toy toy2(toyname2);
    Toy toy3(toyname3);
    Toy toy4(toyname4);
    Toy toy5(toyname5);
    Toy toy6(toyname6);

    cat.addNewToy(toy1);
    cat.addNewToy(toy2);
    cat.addNewToy(toy3);
    cat.addNewToy(toy4);
    cat.addNewToy(toy5);
    cat.addNewToy(toy6);
    ASSERT_EQ(cat.getAmount(), 6);
}

TEST(Cat, getToy1)
{
    std::string name = "Kitty";
    double weight = 25;
    Cat cat(name, weight);

    std::string toyname1 = "toy1";
    std::string toyname2 = "toy2";
    Toy toy1(toyname1);
    Toy toy2(toyname2);
    cat.addNewToy(toy1);
    cat.addNewToy(toy2);

    ASSERT_EQ(cat.getToy(0).getName(), "toy1");
    ASSERT_EQ(cat.getToy(1).getName(), "toy2");
}

TEST(Cat, getToy2)
{
    std::string name = "John";
    double weight = 33;
    Cat cat(name, weight);

    std::string toyname1 = "toy1";
    std::string toyname2 = "toy2";
    std::string toyname3 = "toy3";
    std::string toyname4 = "toy4";
    std::string toyname5 = "toy5";
    std::string toyname6 = "toy6";
    Toy toy1(toyname1);
    Toy toy2(toyname2);
    Toy toy3(toyname3);
    Toy toy4(toyname4);
    Toy toy5(toyname5);
    Toy toy6(toyname6);
    cat.addNewToy(toy1);
    cat.addNewToy(toy2);
    cat.addNewToy(toy3);
    cat.addNewToy(toy4);
    cat.addNewToy(toy5);
    cat.addNewToy(toy6);
    ASSERT_EQ(cat.getToy(0).getName(), "toy1");
    ASSERT_EQ(cat.getToy(1).getName(), "toy2");
    ASSERT_EQ(cat.getToy(2).getName(), "toy3");
    ASSERT_EQ(cat.getToy(3).getName(), "toy4");
    ASSERT_EQ(cat.getToy(4).getName(), "toy5");
    ASSERT_EQ(cat.getToy(5).getName(), "toy6");
    ASSERT_EQ(cat.getAmount(), 6);
}

TEST(Cat, getToy_outOfIndex)
{
    std::string name = "Kitty";
    double weight = 25;
    Cat cat(name, weight);

    std::string toyname = "toy";
    Toy toy(toyname);

    cat.addNewToy(toy);

    ASSERT_THROW(cat.getToy(-1), std::string);
    ASSERT_THROW(cat.getToy(2), std::string);
}

TEST(Cat, getToy_outOfIndex2)
{
    std::string name = "John";
    double weight = 33;
    Cat cat(name, weight);

    std::string toyname1 = "toy1";
    std::string toyname2 = "toy2";
    Toy toy1(toyname1);
    Toy toy2(toyname2);
    cat.addNewToy(toy1);
    cat.addNewToy(toy2);

    ASSERT_THROW(cat.getToy(-2), std::string);
    ASSERT_THROW(cat.getToy(4), std::string);
}

TEST(Cat, isHeavieThan)
{
    std::string name1 = "Kitty";
    std::string name2 = "John";
    double weight1 = 22;
    double weight2 = 30;
    Cat cat1(name1, weight1);
    Cat cat2(name2, weight2);
    ASSERT_FALSE(cat1.isHeavierThan(cat2));
}

TEST(Cat, isHeavieThan2)
{
    std::string name1 = "Kitty";
    std::string name2 = "John";
    double weight1 = 50;
    double weight2 = 10;
    Cat cat1(name1, weight1);
    Cat cat2(name2, weight2);
    ASSERT_TRUE(cat1.isHeavierThan(cat2));
}
