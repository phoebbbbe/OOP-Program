### Homework 02

### Due: 11:59 p.m., 1 November 2021

**In HW02, put all your source code in src/vector_space.h, test code in test/ut_vector_space.h. You can keep files of HW01. But remember to update ut_main.cpp to include ut_vector_space.h**

**Content of HW02**

The goal of this homework is to practice memory management. In HW01, we have learned how to use array for representing vector and compute the inner product. In the sample code of HW02, one sample test for each function `add` and `scale`. Then, you are required to complete the functions `add` and `scale` and add more tests on your own.

You are required to write **7** test cases in total according to following requirement.

Test the following situations:

- add
  - add two vectors properly (2 tests, 20% each)
  - throw exception if vectors are in different dimension (10%)
  - throw exception if vector has 0 or negative dimension (10%)
- scale
  - scale the vector properly (2 tests, 15% each)
  - throw exception if vector has 0 or negative dimension (10%)

**Watch out!** You lose 5 points for each test that has memory leak. You can check memory leak with `valgrind` cmd. you can use `valgrind --leak-check=full --show-leak-kinds=all -v` to see the detailed outputs.

**Note**
1. Use `ASSERT_EQ` to test integer, `ASSERT_NEAR` to test floating-point number, `ASSERT_THROW` to test exception.
2. Please implement your test cases reasonably, otherwise you will get no point for that sub-problem.
3. You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.
