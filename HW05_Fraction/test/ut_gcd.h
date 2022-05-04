#include "../src/gcd.h"

class GcdTest : public::testing::Test
{
protected:
    int a;
    int b;
    int c;
    int d;
    void SetUp() override
    {
        a = 30;
        b = 15;
        c = 20;
        d = -60;
    }
};

TEST_F(GcdTest, gcdPositiveTest1)
{
    ASSERT_EQ(gcd(a, b), 15);
}

TEST_F(GcdTest, gcdPositiveTest2)
{
    ASSERT_EQ(gcd(a, c), 10);
}

TEST_F(GcdTest, gcdPositiveTest3)
{
    ASSERT_EQ(gcd(b, c), 5);
}

TEST_F(GcdTest, gcdNagativeTest)
{
    ASSERT_EQ(gcd(a, d), 30);
}