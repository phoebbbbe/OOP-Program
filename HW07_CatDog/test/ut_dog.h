#include "../src/dog.h"

class DogTest : public::testing::Test {
protected:
    Dog dog1;
    Dog dog2;
    void SetUp() override {
        dog1 = Dog("Doggy", 33);
        dog2 = Dog("FatJohny", 49.9);
    }
};

TEST_F(DogTest, constructTest) {
    ASSERT_EQ(dog1.name(), "Doggy");
    ASSERT_NEAR(dog1.weight(), 33, 0.001);
}

TEST_F(DogTest, constructRangeErrorTest1) {
    ASSERT_THROW(Dog("FatDog", 51), std::range_error);
}

TEST_F(DogTest, constructRangeErrorTest2) {
    ASSERT_THROW(Dog("ThinDog", 9), std::range_error);
}

TEST_F(DogTest, feedTest) {
    dog1.feed();
    ASSERT_NEAR(dog1.weight(), 33.8, 0.001);
}

TEST_F(DogTest, feedOutRangeTest) {
    ASSERT_THROW(dog2.feed(), std::out_of_range);
}