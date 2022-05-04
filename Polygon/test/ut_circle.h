#include "../src/circle.h"

class CircleTest : public::testing::Test {
protected:
    Circle circle1;
    Circle circle2;
    void SetUp() override {
        circle1 = Circle("Shape1", 2.0);
        circle2 = Circle("Shape2", 3.0);
    }
};

TEST_F(CircleTest, constructor) {
    ASSERT_EQ(circle1.getName(), "Shape1");
    ASSERT_EQ(circle2.getName(), "Shape2");
}

TEST_F(CircleTest, perimeter) {
    ASSERT_NEAR(circle1.perimeter(), 12.56, 0.01);
    ASSERT_NEAR(circle2.perimeter(), 18.84, 0.01);
}

TEST_F(CircleTest, area) {
    ASSERT_NEAR(circle1.area(), 12.56, 0.1);
    ASSERT_NEAR(circle2.area(), 28.26, 0.1);
}