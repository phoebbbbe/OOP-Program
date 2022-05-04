#include "../src/binary.h"

TEST(BINARY, OPERATOR=)
{
  int bits[8]={1,0,1,0,1,0,1,0};
  Binary a(bits,8);
  ASSERT_EQ(a, a.operator(b));
}

TEST(BINARY, TO_STRING)
{
  int bits[8]={1,0,1,0,1,0,1,0};
  Binary a(bits,8);
  ASSERT_EQ("10101010",a.toString());
}

TEST(Binary_constructor, Sample1){
  int bits[8]={1,0,1,0,1,0,1,0};
  Binary a(bits,8);
  ASSERT_EQ("10101010",a.toString());
}

TEST(Binary_constructor, Sample2){
  int ab[6]={1,1,1,0,1,0};
  Binary a(ab,6);
  Binary b(a);
  ASSERT_EQ("111010",a.toString());
  ASSERT_EQ("111010",b.toString());
}

TEST(Binary_right_shift, Sample3){
  int ab[4]={1,1,1,0};
  Binary a(ab, 4);
  a>>2;
  ASSERT_EQ("0011",a.toString());
  a>>4;
  ASSERT_EQ("0000",a.toString());
}

TEST(Binary_right_shift, Sample4){
  Binary a;
  ASSERT_ANY_THROW(a>>1);
}
