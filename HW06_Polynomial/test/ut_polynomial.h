//#include <gtest/gtest.h>
#include "../src/polynomial.h"

class PolynomialTest : public::testing::Test
{
protected:
    Term tx1;
    Term tx2;
    Term tx3;
    Term ty1;
    Term ty2;
    Term ty3;
    Term tz1;
    Term tz2;
    Term tz3;
    Term tz4;
    Polynomial px;
    Polynomial py;
    Polynomial pz;
    void SetUp() override
    {
        tx1 = Term(3.9, 1);
        tx2 = Term(2.0, 2);
        tx3 = Term(4.2, 3);
        px = Polynomial({tx1, tx2, tx3}, 3);
        ty1 = Term(0.1, 1);
        ty2 = Term(1.0, 2);
        ty3 = Term(5.8, 4);
        py = Polynomial({ty1, ty2, ty3}, 4);
        tz1 = Term(9.0, 0);
        tz2 = Term(2.2, 2);
        tz3 = Term(4.4, 4);
        tz4 = Term(5.5, 5);
        pz = Polynomial({tz1, tz2, tz3, tz4}, 5);
    }
};

TEST_F(PolynomialTest, TermTest1)
{
    ASSERT_EQ(px.degree(), 3);
    ASSERT_NEAR(px.term(0).coefficient(), 0.0, 0.001);
    ASSERT_NEAR(px.term(1).coefficient(), 3.9, 0.001);
    ASSERT_NEAR(px.term(2).coefficient(), 2.0, 0.001);
    ASSERT_NEAR(px.term(3).coefficient(), 4.2, 0.001);
}

TEST_F(PolynomialTest, TermTest2)
{
    ASSERT_EQ(py.degree(), 4);
    ASSERT_NEAR(py.term(0).coefficient(), 0.0, 0.001);
    ASSERT_NEAR(py.term(1).coefficient(), 0.1, 0.001);
    ASSERT_NEAR(py.term(2).coefficient(), 1.0, 0.001);
    ASSERT_NEAR(py.term(3).coefficient(), 0.0, 0.001);
    ASSERT_NEAR(py.term(4).coefficient(), 5.8, 0.001);
}

TEST_F(PolynomialTest, DuplicateTermTest)
{
    ASSERT_THROW(Polynomial({tx1, tx1, tx2, tx3}, 3), std::string);
}


TEST_F(PolynomialTest, PolyAddition1)
{
    Polynomial pxy = Polynomial();
    pxy = px + py;
    ASSERT_EQ(pxy.degree(), 4);
    ASSERT_NEAR(pxy.term(0).coefficient(), 0.0, 0.001);
    ASSERT_NEAR(pxy.term(1).coefficient(), 4.0, 0.001);
    ASSERT_NEAR(pxy.term(2).coefficient(), 3.0, 0.001);
    ASSERT_NEAR(pxy.term(3).coefficient(), 4.2, 0.001);
    ASSERT_NEAR(pxy.term(4).coefficient(), 5.8, 0.001);
}

TEST_F(PolynomialTest, PolyAddition2)
{
    Polynomial pxz = Polynomial();
    pxz = px + pz;
    ASSERT_EQ(pxz.degree(), 5);
    ASSERT_NEAR(pxz.term(0).coefficient(), 9.0, 0.001);
    ASSERT_NEAR(pxz.term(1).coefficient(), 3.9, 0.001);
    ASSERT_NEAR(pxz.term(2).coefficient(), 4.2, 0.001);
    ASSERT_NEAR(pxz.term(3).coefficient(), 4.2, 0.001);
    ASSERT_NEAR(pxz.term(4).coefficient(), 4.4, 0.001);
    ASSERT_NEAR(pxz.term(5).coefficient(), 5.5, 0.001);
}

TEST_F(PolynomialTest, PolyAdditionEliminate)
{
    Term t1 = Term(1.0, 0);
    Term t2 = Term(2.0, 2);
    Term t3 = Term(-4.2, 3);
    Polynomial pt = Polynomial({t1, t2, t3}, 3);
    Polynomial pxt = Polynomial();
    pxt = px + pt;
    ASSERT_EQ(pxt.degree(), 2);
    ASSERT_NEAR(pxt.term(0).coefficient(), 1.0, 0.001);
    ASSERT_NEAR(pxt.term(1).coefficient(), 3.9, 0.001);
    ASSERT_NEAR(pxt.term(2).coefficient(), 4.0, 0.001);
}

TEST_F(PolynomialTest, PolyMultipleTerm)
{
    Polynomial pt = Polynomial();
    Term t = Term(1, 1);
    pt = px * t;
    ASSERT_EQ(pt.degree(), 4);
    ASSERT_NEAR(pt.term(0).coefficient(), 0.0, 0.001);
    ASSERT_NEAR(pt.term(1).coefficient(), 0.0, 0.001);
    ASSERT_NEAR(pt.term(2).coefficient(), 3.9, 0.001);
    ASSERT_NEAR(pt.term(3).coefficient(), 2.0, 0.001);
    ASSERT_NEAR(pt.term(4).coefficient(), 4.2, 0.001);
}

TEST_F(PolynomialTest, PolyMultiple)
{
    Polynomial pt = Polynomial();
    pt = px * py;
    ASSERT_EQ(pt.degree(), 7);
    ASSERT_NEAR(pt.term(0).coefficient(), 0.0, 0.0001);
    ASSERT_NEAR(pt.term(1).coefficient(), 0.0, 0.0001);
    ASSERT_NEAR(pt.term(2).coefficient(), 0.39, 0.0001);
    ASSERT_NEAR(pt.term(3).coefficient(), 4.1, 0.0001);
    ASSERT_NEAR(pt.term(4).coefficient(), 2.42, 0.0001);
    ASSERT_NEAR(pt.term(5).coefficient(), 26.82, 0.0001);
    ASSERT_NEAR(pt.term(6).coefficient(), 11.6, 0.0001);
    ASSERT_NEAR(pt.term(7).coefficient(), 24.36, 0.0001);
}

TEST_F(PolynomialTest, PolyMultipleEliminate)
{
    Term t1 = Term(1.0, 0);
    Term t2 = Term(2.0, 2);
    Term t3 = Term(-4.2, 3);
    Polynomial pt = Polynomial({t1, t2, t3}, 3);
    Polynomial pxt = Polynomial();
    pxt = px + pt;
    ASSERT_EQ(pxt.degree(), 2);
    ASSERT_NEAR(pxt.term(0).coefficient(), 1.0, 0.001);
    ASSERT_NEAR(pxt.term(1).coefficient(), 3.9, 0.001);
    ASSERT_NEAR(pxt.term(2).coefficient(), 4.0, 0.001);
}