#include "../src/dot.h"

// A single test case has the following form:
//
// TEST(TestSuiteName, TestName) {
//   ... test body ...
// }
TEST(Vector, DotFloat1)
{
    double u[2] = {1.1, 2.2};
    int dim_u = 2;
    double v[2] = {3.3, 4.4};
    int dim_v = 2;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(13.31, result, 0.01);
}

TEST(Vector, DotInt1)
{
    double u[2] = {1, 2};
    int dim_u = 2;
    double v[2] = {3, 4};
    int dim_v = 2;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_EQ(11, result);
}

TEST(Vector, DotFloat2)
{
    double u[3] = {1.1, 2.2, 3.3};
    int dim_u = 3;
    double v[3] = {4.4, 5.5, 6.6};
    int dim_v = 3;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_NEAR(38.72, result, 0.001);
}

TEST(Vector, DotInt2)
{
    double u[3] = {1, 2, 3};
    int dim_u = 3;
    double v[3] = {4, 5, 6};
    int dim_v = 3;
    double result = dot(u, dim_u, v, dim_v);
    ASSERT_EQ(32, result);
}

TEST(Vector, DotException1)
{
    double u[3] = {1, 2, 3};
    int dim_u = 3;
    double v[4] = {4, 5, 6, 7};
    int dim_v = 4;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

TEST(Vector, DotException2)
{
    double u[3] = {4, 5, 6};
    int dim_u = 3;
    double v[4] = {7, 8, 9, 10};
    int dim_v = 4;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

TEST(Vector, DotPass1)
{
    double u[3] = {1, 2, 3};
    int dim_u = -1;
    double v[3] = {4, 5, 6};
    int dim_v = -1;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}

TEST(Vector, DotPass2)
{
    double u[2] = {1, 2};
    int dim_u = -2;
    double v[2] = {3, 4};
    int dim_v = -2;
    ASSERT_THROW(dot(u, dim_u, v, dim_v), std::string);
}