#include <gtest/gtest.h>

#include "ut_student.h"
#include "ut_teacher.h"
#include "ut_school.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
