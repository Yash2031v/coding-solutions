# Climbing Stairs

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

 

 **Example 1:** 

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

```

 **Example 2:** 

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

```

 

 **Constraints:** 

- 1 <= n <= 45

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.7 MB (beats 20.49%)  
**Submitted:** 2026-09-08T04:40:35.981Z  

```cpp
class Solution {
public:
     int helper(int n,vector<int>&dat,int cur){
        if(cur==n+1){
            return 0;
        }
        if(cur==n){
            return 1;
        }
        if(dat[cur]==0){
            dat[cur]= helper(n,dat,cur+1) + helper(n,dat,cur+2);
        }
        return dat[cur];
     }
    int climbStairs(int n) {
        int cur = 0;
        vector<int>dat(n+1);
        return helper(n,dat,cur);

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/climbing-stairs/)