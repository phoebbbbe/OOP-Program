#include "../src/teacher.h"

class TeacherTest : public::testing::Test {
protected:
    Teacher tea1;
    Teacher tea2;
    Student stu1;
    Student stu2;
    void SetUp() override {
        tea1 = Teacher(108590000, "Merry", "CS");
        tea2 = Teacher(108590001, "Beatrice", "CE");
        stu1 = Student(108590000, "Annie", "CS");
        stu2 = Student(108590001, "John", "CE");
    }
};

TEST_F(TeacherTest, ConstructorTest) {
    ASSERT_EQ(tea1.id(), 108590000);
    ASSERT_EQ(tea1.name(), "Merry");
    ASSERT_EQ(tea1.department(), "CS");
    ASSERT_EQ(tea2.id(), 108590001);
    ASSERT_EQ(tea2.name(), "Beatrice");
    ASSERT_EQ(tea2.department(), "CE");
}

TEST_F(TeacherTest, transferTest) {
    tea1.transfer("CE");
    tea2.transfer("IXD");
    ASSERT_EQ(tea1.department(), "CE");
    ASSERT_EQ(tea2.department(), "IXD");
}

TEST_F(TeacherTest, AddStudentTest) {
    tea1.addStudent(stu1);
    tea2.addStudent(stu2);
    ASSERT_EQ(tea1.getStudentById(108590000).id(), 108590000);
    ASSERT_EQ(tea1.getStudentById(108590000).name(), "Annie");
    ASSERT_EQ(tea1.getStudentById(108590000).department(), "CS");
    ASSERT_EQ(tea2.getStudentById(108590001).id(), 108590001);
    ASSERT_EQ(tea2.getStudentById(108590001).name(), "John");
    ASSERT_EQ(tea2.getStudentById(108590001).department(), "CE");
}

TEST_F(TeacherTest, AddStudentErrorTest) {
    ASSERT_THROW(tea1.addStudent(stu2), std::domain_error);
    ASSERT_THROW(tea2.addStudent(stu1), std::domain_error);
}

TEST_F(TeacherTest, GetStudentByIDErrorTest) {
    tea1.addStudent(stu1);
    tea2.addStudent(stu2);
    ASSERT_THROW(tea1.getStudentById(108590001), std::range_error);
    ASSERT_THROW(tea2.getStudentById(108590000), std::range_error);
}