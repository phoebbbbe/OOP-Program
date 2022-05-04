#include "../src/polygon.h"
#include "../src/shape.h"

class PolygonTest : public::testing::Test {
protected:

    Polygon p4;
    Polygon p5;
    Polygon *p;
    Factory f;
    void SetUp() override {
        int dim = 2;
        double x1[2] = {1, 0};
        double x2[2] = {1, 3};
        double x3[2] = {4, 3};
        double x4[2] = {4, 0};
        MathVector m1(dim, x1);
        MathVector m2(dim, x2);
        MathVector m3(dim, x3);
        MathVector m4(dim, x4);
        MathVector v[4] = {m1, m3, m2, m4}; //vertex傳進來時不一定是順序的
        // v[0](m1), v[1](m3) ... , v[4] -> unknown
        //p4 = Polygon::createPolygon(4, v);
        //p4 = Factory::createPolygon(4, v); (way1.)
        p4 = f.createPolygon(4, v); //(way2.)
        // 進階到五邊形的測資
        double a1[2] = {0, 0};
        double a2[2] = {2, 0};
        double a3[2] = {2, 4};
        double a4[2] = {2, 5};
        double a5[2] = {0, 4};
        MathVector m21(dim, a1);
        MathVector m22(dim, a2);
        MathVector m23(dim, a3);
        MathVector m24(dim, a4);
        MathVector m25(dim, a5);
        MathVector v2[5] = {m21, m24, m25, m23, m22}; //vertex傳進來時不一定是順序的
        p5 = createPolygonSA(5, v2);
        //p5 = Polygon::createPolygon(5, v2);
        //MathVector u[3] = {m1, m2, m3};
        //p3 = Poloygon(3, u);
        /* Shape* polygon = new Polygon();
        polygon->perimeter();
        Shape* triangle = new Triangle(); */
        // p = ＆Polygon::createPolygon(5, v2); illegal : 因為createPolygon() 回傳的是物件而非指引，所以會呼叫 copy assignment 在遇到"="後才會被copy，但&在還沒copy時就要取地址，但此時函式執行完 東西已消失，取不到東西
        p = &p5;
    }
};

TEST_F(PolygonTest, polygon) {
    ASSERT_NEAR(p->perimeter(), (double)(11+std::sqrt(5)), 0.001);
}
/* TEST_F(PolygonTest, centroidTest) {
    //ASSERT_NEAR(p4.getCentroid(), ....) 因為 assert_near 不會知道要怎麼幫兩個 mathvector 做比較，所以應該用 at(0) 抓出它知道的資料型態來做比較
    ASSERT_NEAR(p4.getCentroid().at(0), 2.5, 0.01);
    ASSERT_NEAR(p4.getCentroid().at(1), 1.5, 0.001);
} */

TEST_F(PolygonTest, perimeterTestP4) {
    ASSERT_NEAR(p4.perimeter(), 12.0, 0.001);
}
TEST_F(PolygonTest, areaTestP4) {
    ASSERT_NEAR(p4.area(), 9.0, 0.001);
}

TEST_F(PolygonTest, perimeterTestP5) {
    ASSERT_NEAR(p5.perimeter(), (double)(11+std::sqrt(5)), 0.001); // sqrt(5)的小數點可能很多，因此加上(double) 強制轉型
}
TEST_F(PolygonTest, areaTestP5) {
    ASSERT_NEAR(p5.area(), 9.0, 0.001);
}

/* TEST_F(PolygonTest, perimeterCompare) {
    ASSERT_FALSE(p5 < p3);
} */

TEST(StdSort, simpleSort) {
    int a[5] = {1, 3, 2, 6, 5};
    std::vector<int> b;
    for(int i = 0; i < 5; i++){
        b.push_back(a[i]);
    }
    std::sort(b.begin(), b.begin() + b.size()); // aka b.end()
    std::sort(a, a + 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(b[4], 6);
}

bool greaterThan(int a, int b) {
    return (a > b);
}

TEST(StdSort, simpleSort2) { // descending
    int a[5] = {1, 3, 2, 6, 5};
    std::sort(a, a + 5, greaterThan);
    ASSERT_EQ(a[0], 6);
}

bool distanceToNine(int a, int b) {
    return (9 - a) > (9 -b);
}

TEST(StdSort, simpleSort3) { // descending
    int a[5] = {1, 3, 2, 6, 5};
    std::sort(a, a + 5, distanceToNine);
    ASSERT_EQ(a[0], 1);
}
