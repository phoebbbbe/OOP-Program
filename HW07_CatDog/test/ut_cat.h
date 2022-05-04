#include "../src/cat.h"

class CatTest : public::testing::Test {
protected:
    Cat cat1;
    Cat cat2;
    void SetUp() override {
        cat1 = Cat("Lucky", 2.5);
        cat2 = Cat("FatAmy", 5.9);
    }
};

TEST_F(CatTest, constructTest) {
    ASSERT_EQ(cat1.name(), "Lucky");
    ASSERT_NEAR(cat1.weight(), 2.5, 0.001);
}

TEST_F(CatTest, constructRangeErrorTest1) {
    ASSERT_THROW(Cat("FatCat", 6.6), std::range_error);
}

TEST_F(CatTest, constructRangeErrorTest2) {
    ASSERT_THROW(Cat("ThinCat", 1.5), std::range_error);
}

TEST_F(CatTest, feedTest) {
    cat1.feed();
    ASSERT_NEAR(cat1.weight(), 2.7, 0.001);
}

TEST_F(CatTest, feedOutRangeTest) {
    ASSERT_THROW(cat2.feed(), std::out_of_range);
}