# Homework 01

> This homework and content were created by 黃漢軒 (109590031), please feel free to ask me if you have any questions.
>
> Email: [t10950031@ntut.org.tw](mailto:t10950031@ntut.org.tw)／MS Team: 黃漢軒

⚠️ Due: 11:59 p.m., 7 October 2022 ⚠️



## About and goal

This Homework has these goals:

1. Know how to use Git.
2. Make sure you have basic knowledge about C/C++.
3. Know how to deal with an invalid value.

Before you start HW#01, you should remove all files in your repo, or you will have push-rejected issues when you push.



## Remove all files in your project

Before you start Homework 01, you should remove Homework 00 in your repo.

1. Enter into WSL.

   ```
   bash
   ```

2. Change the directory to your project if necessary.

   ```
   cd /the/path/of/your/project
   ```

3. Use git to do the following step:

   ```
   git pull
   git rm *
   git commit -m 'remove HW00'
   git push
   ```

4. Check your repo on Gitlab is clean or not.

**After these steps, you should check your GitLab repo is clean, or you will have a push-rejected issue when you push homework to the repo.**

## Folder Structure Tree
   ```
   bin/
   ├─ ut_all
   src/
   ├─ cookie.h
   test/
   ├─ ut_cookie.h
   ├─ ut_main.cpp
   makefile
   ```

## The content of Homework 01

### Description

Xuan is like to eat cookies. He has $`N`$ cookies in his cookie jar.

Xuan defines the "delicious-value" $`d_v`$ in every cookie $`a_i`$, which means how delicious the cookie is.
The delicious-value range $`d_v`$ should be between $`0`$ to $`100`$.

Xuan line up every cookie in cookie jar from left to right, and decides to eat the cookie in every odd position **or** even position, but he also wants to have the max delicious value that can make him happy.

But Xuan is bad at math, so he wants you to write a function to help him.

Give you a sequence contains $`N`$ value, represent the $`N`$ cookies' delicious value.
You should implement the following function, let Xuan know how to eat cookies to have more delicious value.

<img src="https://i.imgur.com/5MgDWqG.png" alt="image-20220727234456298" style="zoom:67%;" />

### Function

```c++
int max_dv(int n, int* array)
```

Parameter:

​	array: the sequence of delicious value, every element of the sequence $`a_i`$ should be between 0 to 100.

Return:

​	You should total the delicious value in the odd position, call $`t_o`$, and in the even position, call $`t_e`$, return the max delicious value between $`t_o`$ and $`t_e`$, that is, $`\max(t_o, t_e)`$

​	**If the sequence has any invalid value, or the amount of cookie is negative, you should return $`-1`$.**



### Sample

These test cases can let you know whether your code is working correctly or not.

#### Sample #1

```
max_dv(4, {1, 2, 3, 4})
```

```
Output: 6
```

In sequence $`[1, 2, 3, 4]`$, the total delicious value $`d_v`$ in odd position is $`t_o=1 + 3 = 4`$, in even position is $`t_e = 2 + 4=6`$

Therefore, you should return the max value between $`t_o`$ and $`t_e`$, which is 6.



#### Sample #2

```
max_dv(4, {1, -3, 3, 4})
```

```
Output: -1
```

In sequence $`[1, -3, 3, 4]`$, the delicious value in the 2nd cookie $`a_2`$ is a negative value, that is, not in the range between $`0`$ to $`100`$.

Therefore, you should return $`-1`$.



#### Sample #3

```
max_dv(-4, {1, -3, 3, 4})
```

```
Output: -1
```

The amount of the cookies $`N`$ is a negative value $`-4`$.

Therefore, you should return $`-1`$.



### Notice

1. You should write 8 test cases to validate your programming work correctly.

   - $`[10pt]`$ Write two test cases to test when cookie amount $`N`$ is even.

   - $`[10pt]`$ Write two test cases to test when cookie amount $`N`$ is odd.

   - $`[10pt]`$ Write two test cases to test when delicious value $`d_v`$ is negative.

   - $`[5pt]`$ Write two test cases to test when cookie amount $`N`$ is negative.

2. Use `ASSERT_EQ` to test integers, `ASSERT_NEAR` to test floating-point numbers, and `ASSERT_THROW` to test exceptions.

3. **Please implement your test cases reasonably, otherwise, you will get no point for that sub-problem.**

4. In secret testcases, the cookie amount $`N`$ must be equals the sequence length when the cookie amount $`N`$ is not the negative number.



### After you finish

You should upload the files (exclude bin) to GitLab by following steps given in HW00. You are required to understand the meaning of each commands (`git add`, `git commit`, `git push`) so that you won't make a mistake. Hint: You should start from `git add`.

You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). 

**You will lost 10% if you bin folder contains compiled `ut_all` in git repo.**



### Meme

<img src="https://i.imgflip.com/6o375m.jpg" alt="img" style="zoom: 80%;" />

