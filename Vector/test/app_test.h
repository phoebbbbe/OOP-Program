#include "../src/app.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/polygon.h"
#include "../src/util.h"

class AppTest : public ::testing::Test {
protected:
    int dim;
    double v[2];
    double u[2];
    double w[2];
    MathVector mv;
    MathVector mv1;
    MathVector mv2;
    void SetUp() override {
        dim = 2;
        v[0] = 0;
        v[1] = 0;
        u[0] = 0;
        u[1] = 3;
        w[0] = 4;
        w[1] = 0;
        mv = MathVector(dim, v);
        mv1 = MathVector(dim, u);
        mv2 = MathVector(dim, w);
        Shape::resetLog();
    }

    void TearDown() override {
        Shape::resetLog();
    }
};

TEST_F(AppTest, ShapeConstructorBefor) {
    ASSERT_EQ("", Shape::log);
}

TEST_F(AppTest, ShapeConstructor) {
    Shape* s = new Triangle(); //pure virtual constructor 不能直接實體化為一個物件，只能用做一個指針
    ASSERT_EQ("=>Shape =>Triangle ", Shape::log);
}

TEST_F(AppTest, ShapeConstructorWithDelete) {
    Shape* s = new Triangle(); //pure virtual constructor 不能直接實體化為一個物件，只能用做一個指針
    delete s;
    ASSERT_EQ("=>Shape =>Triangle =>~Triangle =>~Shape ", Shape::log);
}

TEST_F(AppTest, AddTest) {
    App app;
    app.add(new Circle(10)); // 10*10*3.14 = 314
    app.add(new Circle(15)); // 15*15*3.14 = 706.5
    app.add(new Triangle(mv, mv1, mv2, "T")); // (0,0),(0,3),(4,0) area = 6
    app.sort();
    ASSERT_NEAR(app.at(0)->area(), 6, 1);
    ASSERT_NEAR(app.at(1)->area(), 314, 1);
    ASSERT_NEAR(app.at(2)->area(), 706.5, 1);
}

TEST_F(AppTest, SortTest) {
    App app;
    app.add(new Circle(10)); // 10*10*3.14 = 314
    app.add(new Circle(15)); // 15*15*3.14 = 706.5
    app.add(new Triangle(mv, mv1, mv2, "T")); // (0,0),(0,3),(4,0) area = 6
    app.sort();
    ASSERT_NEAR(app.at(0)->area(), 6, 1);
    ASSERT_NEAR(app.at(1)->area(), 314, 1);
    ASSERT_NEAR(app.at(2)->area(), 706.5, 1);
}

TEST(ShapeFF, Triangle) {
    std::vector <Shape *> s = shapesFromFile("input.txt"); // 放入相對於ut_all的路徑
    ASSERT_EQ(s[0]->getName(), "Triangel:: triangle");
}