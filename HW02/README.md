# Homework 02

> This homework and content were created by 黃漢軒 (109590031), please feel free to ask me if you have any questions.
>
> Email: [t10950031@ntut.org.tw](mailto:t10950031@ntut.org.tw)／Discord: Cylinder#1811

⚠️ Due: 11:59 p.m., 14 / 10 / 2022 ⚠️



## Goal

This home work has these goal:

- Know how to deal with memory leak, practice memory management.
- Know how to use Git.

Please make sure you know how to use Git, and know how to deal with conflict in Git.

**Please make sure all the code is written by you, or you will lost all of the score :)**



## Content

Uriah have a lot of cookie, and Uriah enjoy placing these cookie to make a beautiful design.

Uriah will place these cookie to a 10x10 grid.

<img src="https://cdn.discordapp.com/attachments/989547753606631486/1012340811716886619/unknown.png" alt="img" style="zoom:67%;" />

He will place the first cookie in left-bottom $`(9, 0)`$, and doing these operation:

1. Operation T: Place next cookie in the top of the current cookie.
2. Operation R: Place next cookie in the right of the current cookie.
3. Calculate Row: Calculate the count of cookie in the specific row.
4. Calculate Column: Calculate the count of cookie in the specific column.



For example, if Uriah execute following operation: 

```
TTRRTRTR
```

After these operation, the cookie will place like following grid.

<img src="https://cdn.discordapp.com/attachments/989547753606631486/1012371505516118057/unknown.png" alt="img" style="zoom:67%;" />



If Uriah want to know count of cookie in the row $`7`$, he will know there are $`3`$ blocks in this row.

In this task, you have to satisfy Uriah's operation by writing $`4`$ function.



## Function

In this task, you have to implement 4 function.

```c++
/**
 * Place next cookie in the top of the current cookie. (Operation T)
 * args:
 *     bool** grid: The grid which Uriah place the cookie.
 */
void placeTop(bool** grid){
    ...
}
```

```c++
/**
 * Place next cookie in the right of the current cookie.
 * args:
 *     bool** grid: The grid which Uriah place the cookie.
 */
void placeRight(bool** grid){
    ...
}
```

```c++
/**
 * Calculate the count of cookie in the specific row.
 * args:
 *     bool** grid: The grid which Uriah place the cookie.
 *     int    row: The specific row Uriah want to know the count of cookie.
 */
int calcRow(bool** grid, int row){
    ...
}
```

```c++
/**
 * Calculate the count of cookie in the specific column.
 * args:
 *     bool** grid: The grid which Uriah place the cookie.
 *     int    row: The specific column Uriah want to know the count of cookie.
 */
int calcColumn(bool** grid, int column){
    ...
}
```

- If the position which cookie place is out of grid range, please throw a string exception: `out of range.`
- If the row/column number is out of grid range, please return $`-1`$.
- **If any irregular situation happen, you should cancel the move.**



## Sample

These test cases can let you know whether your code is working correctly or not.

### Sample #1

```c++
placeTop(grid);
placeRight(grid);
placeTop(grid);
placeRight(grid);
calcRow(grid, 8); // The first output
calcColumn(grid, 1); // The second output
```

```
Output: 2
Output: 2
```

After following step is execute, you can get the result in the grid.

<img src="https://cdn.discordapp.com/attachments/989547753606631486/1012367563268816927/unknown.png" alt="img" style="zoom:67%;" />

You can find that the count of cookie in row $`8`$ is $`2`$, also the count of cookie in column $`1`$ is $`2`$.



### Sample #2

```c++
placeTop(grid);
placeTop(grid);
placeTop(grid);
calcRow(grid, 0); // The first output
calcRow(grid, 8); // The second output
calcColumn(grid, 0); // The third output
```

```
Output: 0
Output: 1
Output: 4
```

After following step is execute, you can get the result in the grid.

<img src="https://cdn.discordapp.com/attachments/989547753606631486/1012368614474645585/unknown.png" alt="img" style="zoom:67%;" />

You can find that:

- The count of cookie in row $`0`$ is $`0`$, 

- The count of cookie in row $`8`$ is $`1`$.

- The count of cookie in column $`0`$ is $`4`$.



### Sample #3

```c++
placeTop(grid);
/* ... placeTop(grid) 8 times ... */
placeTop(grid);
```

```
Output: out of range.
```

After following step is execute, you can get the result in the grid.

<img src="https://cdn.discordapp.com/attachments/989547753606631486/1012370551572025395/unknown.png" alt="img" style="zoom:67%;" />

The last of `placeTop(grid)` will out of grid range, you should throw exception after execute it.



### Sample #4

```c++
calcRow(grid, 48763);
```

```
Output: -1
```

The row index of grid only between $`0`$ to $`9`$, $`48763`$ not in range, so you should return $`-1`$ when you execute it.



## Judge

- 35%: The testcase write by you.
  - $`[10\%]`$ Write 2 testcase to test regular situation, contains calculate any row or column.
  - $`[10\%]`$ Write 2 testcase to test that the placed cookie out or grid range.
  - $`[10\%]`$ Write 2 testcase to test that the query of calculate column or row is out of grid range.
  - $`[5\%]`$ Write 1 testcase to test that place over 10 times, then calculate any row or column.
- 65%: The secret testcase write by TA.
  - $`[5\%]`$ The first 4 testcase is [sample](#sample).
  - $`[60\%]`$ Secret testcase.



## Note

1. Use `ASSERT_EQ` to test integer, `ASSERT_NEAR` to test floating-point number, `ASSERT_THROW` to test exception.
2. Please implement your test cases reasonably, otherwise you will get no point for that sub-problem.
3. **You should neiter not add bin folder to your git, nor add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.**
4. **You lose 5 points for each test that has memory leak. You can check memory leak with `valgrind` cmd.**



## Meme

![image.png](https://media.discordapp.net/attachments/950048467294760990/1028252004692283422/unknown.png)
