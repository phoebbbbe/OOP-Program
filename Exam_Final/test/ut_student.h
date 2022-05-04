#include "../src/student.h"


class StudentTest : public::testing::Test {
protected:
    Student stu1;
    Student stu2;
    void SetUp() override {
        stu1 = Student(108590000, "Annie", "CS");
        stu2 = Student(108590001, "John", "CE");
    }
};

TEST_F(StudentTest, ConstructorTest) {
    ASSERT_EQ(stu1.id(), 108590000);
    ASSERT_EQ(stu1.name(), "Annie");
    ASSERT_EQ(stu1.department(), "CS");
    ASSERT_EQ(stu2.id(), 108590001);
    ASSERT_EQ(stu2.name(), "John");
    ASSERT_EQ(stu2.department(), "CE");
}

TEST_F(StudentTest, transferTest) {
    stu1.transfer("CE");
    stu2.transfer("IXD");
    ASSERT_EQ(stu1.department(), "CE");
    ASSERT_EQ(stu2.department(), "IXD");
}

TEST_F(StudentTest, ScoreTest) {
    stu1.addScore(98.9);
    stu1.addScore(80);
    stu1.addScore(99);
    ASSERT_NEAR(stu1.getScore(1), 98.9, 0.01);
    ASSERT_NEAR(stu1.getScore(2), 80.0, 0.01);
    ASSERT_NEAR(stu1.getScore(3), 99, 0.01);
}

TEST_F(StudentTest, ScoreIndexErrorTest) {
    stu1.addScore(98.9);
    stu1.addScore(80);
    ASSERT_THROW(stu1.getScore(3), std::out_of_range);
}

TEST_F(StudentTest, NoScoreTest) {
    ASSERT_THROW(stu1.scoreAverage(), std::range_error);
}
