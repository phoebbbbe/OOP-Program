### Homework 01

### Due: 11:59 p.m., 15 October 2021

**Before HW01, you shuold remove HW00**

1. In bash, go to your git folder and do the following to remove HW00 from both local and remove repositories.

- git pull
- git rm *
- git commit -am "remove HW00"
- git push

2. Then, in the actual git folder, move files of HW00 to backup folder

3. Download source code from this reop and put it in your git folder

**After above steps, here are the actual content of HW01**

In class, we have discussed how to write unit test with google test library and the implementation of vector with double array. This homework requires to complete the `dot` function (50%) for deriving the dot product two vectors of the same dimension. Note that you need to ensure the dimension are the same before conducting dot computation. If any unexpect inputs, you shuold throw a string "undefined." at exception. Part of the source code and makefile are provided.

After finishing the `dot` function, at least 8 test cases are required from you in this homework. (1 for each listed items.)

- Test the following situations:
  - 2-dimensional vector dot 2-dimensional vector (15%)
  - 3-dimensional vector dot 3-dimensional vector (10%)
  - 3-dimensional vector dot 4-dimensional vector (15%)
  - pass -1 as dimension parameter (dim_u, dim_v) (10%)

**Note**
1. Use `ASSERT_EQ` to test integer, `ASSERT_NEAR` to test floating-point number, `ASSERT_THROW` to test exception.
2. Please implement your test cases reasonably, otherwise you will get no point for that sub-problem.

**After finishing the function and testcases of HW01**

You should upload the files (exclude bin) to GitLab by following steps given in HW00. You are required to understand the meaning of each commands (`git add`, `git commit`, `git push`) so that you won't make a mistake. Hint: You should start from `git add`.

You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.
