# Power of Four

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `n`, return  *`true` if it is a power of four. Otherwise, return `false`*.

An integer `n` is a power of four, if there exists an integer `x` such that `n == 4x`.

 

 **Example 1:** 

```
Input: n = 16
Output: true

```

 **Example 2:** 

```
Input: n = 5
Output: false

```

 **Example 3:** 

```
Input: n = 1
Output: true

```

 

 **Constraints:** 

- -231 <= n <= 231 - 1

 

 **Follow up:**  Could you solve it without loops/recursion?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.8 MB (beats 80.43%)  
**Submitted:** 2026-09-07T06:47:06.742Z  

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n%4!=0){
            return false;
        }
        return isPowerOfFour(n/4);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/power-of-four/)