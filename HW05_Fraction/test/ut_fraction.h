#include "../src/fraction.h"

class FractionTest : public::testing::Test
{
protected:
    Fraction f1;
    Fraction f2;
    Fraction f3;
    Fraction f4;
    void SetUp() override
    {
        int num1 = -4;
        int num2 = 3;
        int num3 = 2;
        f1 = Fraction(); // + 0 1
        f2 = Fraction(num1); // - 4 1
        f3 = Fraction(num2, num3); // + 3 2
        f4 = Fraction(num1, num3); // - 2 1
    }
};

TEST_F(FractionTest, Constructor1)
{
    ASSERT_EQ(f1.numerator(), 0);
    ASSERT_EQ(f1.denominator(), 1);
    ASSERT_EQ(f1.sign(), '+');
}

TEST_F(FractionTest, Constructor2)
{
    ASSERT_EQ(f2.numerator(), 4);
    ASSERT_EQ(f2.denominator(), 1);
    ASSERT_EQ(f2.sign(), '-');
}

TEST_F(FractionTest, Constructor3)
{
    ASSERT_EQ(f3.numerator(), 3);
    ASSERT_EQ(f3.denominator(), 2);
    ASSERT_EQ(f3.sign(), '+');
}

TEST_F(FractionTest, Constructor4)
{
    ASSERT_EQ(f4.numerator(), 2);
    ASSERT_EQ(f4.denominator(), 1);
    ASSERT_EQ(f4.sign(), '-');
}

TEST_F(FractionTest, ConstructorDividedZeroTest)
{
    ASSERT_THROW(Fraction(5, 0), std::string);
}

TEST_F(FractionTest, toString1)
{
    ASSERT_EQ(f1.toString(), "0");
}

TEST_F(FractionTest, toString2)
{
    ASSERT_EQ(f2.toString(), "-4");
}

TEST_F(FractionTest, toString3)
{
    ASSERT_EQ(f3.toString(), "3/2");
}

TEST_F(FractionTest, toString4)
{
    ASSERT_EQ(f4.toString(), "-2");
}

TEST_F(FractionTest, operatorAdd1)
{
    Fraction r = Fraction();
    r = f1 + f2;
    ASSERT_EQ(r.sign(), '-');
    ASSERT_EQ(r.numerator(), 4);
    ASSERT_EQ(r.denominator(), 1);
}

TEST_F(FractionTest, operatorAdd2)
{
    Fraction r = Fraction();
    r = f2 + f3;
    ASSERT_EQ(r.sign(), '-');
    ASSERT_EQ(r.numerator(), 5);
    ASSERT_EQ(r.denominator(), 2);
}

TEST_F(FractionTest, operatorAdd3)
{
    Fraction r = Fraction();
    r = f2 + f4;
    ASSERT_EQ(r.sign(), '-');
    ASSERT_EQ(r.numerator(), 6);
    ASSERT_EQ(r.denominator(), 1);
}

TEST_F(FractionTest, operatorAdd4)
{
    Fraction r = Fraction();
    r = f3 + f4;
    ASSERT_EQ(r.sign(), '-');
    ASSERT_EQ(r.numerator(), 1);
    ASSERT_EQ(r.denominator(), 2);
}

TEST_F(FractionTest, operatorPlus1)
{
    Fraction r = Fraction();
    r = f1 - f2;
    ASSERT_EQ(r.sign(), '+');
    ASSERT_EQ(r.numerator(), 4);
    ASSERT_EQ(r.denominator(), 1);
}

TEST_F(FractionTest, operatorPlus2)
{
    Fraction r = Fraction();
    r = f2 - f3;
    ASSERT_EQ(r.sign(), '-');
    ASSERT_EQ(r.numerator(), 11);
    ASSERT_EQ(r.denominator(), 2);
}

TEST_F(FractionTest, operatorPlus3)
{
    Fraction r = Fraction();
    r = (f3 - f4) + f3;
    ASSERT_EQ(r.sign(), '+');
    ASSERT_EQ(r.numerator(), 5);
    ASSERT_EQ(r.denominator(), 1);
}

TEST_F(FractionTest, operatorPlus4)
{
    Fraction r = Fraction();
    r = f4 - f3;
    ASSERT_EQ(r.sign(), '-');
    ASSERT_EQ(r.numerator(), 7);
    ASSERT_EQ(r.denominator(), 2);
}

TEST_F(FractionTest, operatorDivide1)
{
    Fraction r = Fraction();
    r = f1 / f2;
    ASSERT_EQ(r.sign(), '+');
    ASSERT_EQ(r.numerator(), 0);
    ASSERT_EQ(r.denominator(), 1);
}

TEST_F(FractionTest, operatorDivide2)
{
    Fraction r = Fraction();
    r = f2 / f3;
    ASSERT_EQ(r.sign(), '-');
    ASSERT_EQ(r.numerator(), 8);
    ASSERT_EQ(r.denominator(), 3);
}

TEST_F(FractionTest, operatorDivide3)
{
    Fraction r = Fraction();
    r = f2 / f4;
    ASSERT_EQ(r.sign(), '+');
    ASSERT_EQ(r.numerator(), 2);
    ASSERT_EQ(r.denominator(), 1);
}

TEST_F(FractionTest, operatorDivide4)
{
    Fraction r = Fraction();
    r = f4 / f2;
    ASSERT_EQ(r.sign(), '+');
    ASSERT_EQ(r.numerator(), 1);
    ASSERT_EQ(r.denominator(), 2);
}

TEST_F(FractionTest, operatorDivideByZero)
{
    ASSERT_THROW(f2 / f1, std::string);
}
