#include "../src/school.h"
#include "../src/school_member.h"
#include "../src/teacher.h"
#include "../src/student.h"
#include "../src/school_member.h"

class SchoolTest : public::testing::Test {
protected:
    School school;
    SchoolMember* member1;
    SchoolMember* member2;
    SchoolMember* member3;
    SchoolMember* member4;
    void SetUp() override {
        member1 = new Teacher(108591001, "Merry", "CS");
        member2 = new Teacher(108591002, "Beatrice", "CE");
        member3 = new Student(108590001, "Annie", "CS");
        member4 = new Student(108590002, "John", "CE");
    }

    void TearDown() override {
        delete member1;
        delete member2;
        delete member3;
        delete member4;
    }
};

TEST_F(SchoolTest, ConstructorTest) {
    school.addSchoolMember(member1);
    school.addSchoolMember(member2);
    school.addSchoolMember(member3);
    school.addSchoolMember(member4);
    ASSERT_EQ(school.at(0)->name(), "Merry");
    ASSERT_EQ(school.at(1)->name(), "Beatrice");
    ASSERT_EQ(school.at(2)->name(), "Annie");
    ASSERT_EQ(school.at(3)->name(), "John");
}

