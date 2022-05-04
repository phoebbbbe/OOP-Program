#include "../src/triangle.h"

class TriangleTest : public::testing::Test {
protected:
    Triangle triangle1;
    Triangle triangle2;
    Circle circle1;
    Circle circle2;
    void SetUp() override {
        triangle1 = Triangle("Shape1", 2.0);
        triangle2 = Triangle("Shape2", 3.0);
        circle1 = Circle("Shape11", 2.0);
        circle2 = Circle("Shape12", 3.0);
    }
};

TEST_F(TriangleTest, ConstructorTest) {
    ASSERT_EQ(triangle1.getName(), "Shape1");
    ASSERT_EQ(triangle2.getName(), "Shape2");
}

TEST_F(TriangleTest, PerimeterTest) {
    ASSERT_NEAR(triangle1.perimeter(), 12.56, 0.01);
    ASSERT_NEAR(triangle2.perimeter(), 18.84, 0.01);
}

TEST_F(TriangleTest, AreaTest) {
    ASSERT_NEAR(triangle1.area(), 12.56, 0.1);
    ASSERT_NEAR(triangle2.area(), 28.26, 0.1);
}

TEST_F(TriangleTest, AddCircleTest) {
    triangle1.addCircle(&circle1);
    triangle1.addCircle(&circle2);
    ASSERT_EQ(triangle1.getCircle(0)->getName(), "Shape11");
    ASSERT_EQ(triangle1.getCircle(1)->getName(), "Shape12");
}