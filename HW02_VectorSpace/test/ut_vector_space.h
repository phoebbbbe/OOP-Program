#include "../src/vector_space.h"

const double DELTA = 0.001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.

TEST(VectorTest, AddProper1) {
  double u[3] = {1, 2, 3};
  double v[3] = {1.5, 2.5, 3.5};
  int dim = 3;;

  double * result = add(u, dim, v, dim);

  EXPECT_NEAR(2.5, result[0], DELTA);
  EXPECT_NEAR(4.5, result[1], DELTA);
  EXPECT_NEAR(6.5, result[2], DELTA);

  delete [] result;   // heap allocation in 'add'
}

TEST(VectorTest, AddProper2) {
  double u[4] = {4, 5, 6, 7};
  double v[4] = {6, 5, 4, 3};
  int dim = 4;

  double * result = add(u, dim, v, dim);

  EXPECT_NEAR(10.0, result[0], DELTA);
  EXPECT_NEAR(10.0, result[1], DELTA);
  EXPECT_NEAR(10.0, result[2], DELTA);
  EXPECT_NEAR(10.0, result[3], DELTA);

  delete [] result;   // heap allocation in 'add'
}

TEST(VectorTest, AddDiff) {
  double u[4] = {4, 5, 6, 7};
  double v[3] = {6, 5, 4};
  int dim_u = 4;
  int dim_v = 3;

  ASSERT_THROW(add(u, dim_u, v, dim_v), std::string);
}

TEST(VectorTest, AddError) {
  double u[3] = {4, 5, 6};
  double v[3] = {6, 5, 4};
  int dim_u = 0;
  int dim_v = -1;

  ASSERT_THROW(add(u, dim_u, v, dim_v), std::string);
}

TEST(VectorTest, ScaleProper1) {
  double u[3] = {1.5, 2.5, 3.5};
  int dim = 3;
  double n = 1.2;
  double * result = scale(u, dim, n);

  EXPECT_NEAR(1.8, result[0], DELTA);
  EXPECT_NEAR(3.0, result[1], DELTA);
  EXPECT_NEAR(4.2, result[2], DELTA);

  delete [] result;  // heap allocation in 'scale'
}

TEST(VectorTest, ScaleProper2) {
  double u[4] = {1.5, 2.5, 3.5, 4.5};
  int dim = 4;
  double n = 1.4;

  double * result = scale(u, dim, n);

  EXPECT_NEAR(2.1, result[0], DELTA);
  EXPECT_NEAR(3.5, result[1], DELTA);
  EXPECT_NEAR(4.9, result[2], DELTA);
  EXPECT_NEAR(6.3, result[3], DELTA);

  delete [] result;  // heap allocation in 'scale'
}

TEST(VectorTest, ScaleError)
{
  double u[4] = {1.5, 2.5, 3.5, 4.5};
  int dim = 0;
  double n = 1.4;

  ASSERT_THROW(scale(u, dim, n), std::string);
}
