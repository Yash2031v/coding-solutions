# APDIS

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Progressive Purge

 *This is the easy version of the problem. The two versions differ only in the constraints on $N$. Here, $N \le 4000$ and $\sum N^2 \le 4000^2$ across all tests.* 

An array $B$ of length $M$ is called  *good*  if there exists a pair of integers $(i, d)$ satisfying the following conditions:

- $d \ge 2$, and
- Delete every element $B_j$ at an index $j$ such that $j \equiv i \pmod d$. Then, the resulting sequence is sorted in non-decreasing order.

You are given an array $A$. Count the number of its contiguous subarrays that are  *good*.

That is, count the number of pairs $(L, R)$ such that $1 \le L \le R \le N$ and the array
$[A_L, \ldots, A_R]$ is  *good*.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integer $N$. The second line contains $N$ space-separated integers $A_1, \ldots, A_N$.
### Output Format

For each test case, output on a new line the number of good subarrays of $A$.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 4000$
- $1 \le A_i \le N$
- The sum of $N^2$ over all test cases won't exceed $4000^2$.
### Sample 1:
Input
Output

```
6
2
2 1
1
1
4
2 2 1 1
5
3 4 2 1 1
7
3 7 1 5 2 6 4
10
7 2 9 1 5 7 3 8 2 6

```

```
3
1
9
12
24
38

```

### Explanation:

 **Test case $1$:**  There are three subarrays. The singletons are good because they're already sorted, and $[2, 1]$ is good because you can choose for example $(1, 3)$ to delete the first element, leaving a sorted array.

 **Test case $2$:**  There's only one subarray and it's sorted.

 **Test case $3$:**  There are $10$ subarrays. Among them, only $[2, 2, 1, 1]$ is not good - it can be verified that it's impossible to make it sorted by deleting elements at an arithmetic progression of indices.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-26T15:57:29.638Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}

```

---

[View on CodeChef](https://www.codechef.com/problems/APDIS)