#include <gtest/gtest.h>

#include "ut_circle.h"
#include "ut_triangle.h"
#include "ut_app.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
