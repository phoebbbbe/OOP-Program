#include "../src/app.h"
#include "../src/shape.h"
#include "../src/triangle.h"
#include "../src/circle.h"

class AppTest : public ::testing::Test {
protected:
    App app;
    Shape* shape1;
    Shape* shape2;
    Shape* shape3;
    void SetUp() override{
        shape1 = new Circle("shape1", 2);
        shape2 = new Triangle("shape2", 3);
        shape3 = new Circle("shape3", 4);
    }
    void TearDown() override {
        delete shape1;
        delete shape2;
        delete shape3;
    }
};

TEST_F(AppTest, ShapeConstructor) {
    app.addShape(shape1);
    app.addShape(shape2);
    app.addShape(shape3);
    ASSERT_EQ(app.at(0)->getName(), "shape1");
    ASSERT_EQ(app.at(1)->getName(), "shape2");
    ASSERT_EQ(app.at(2)->getName(), "shape3");
}