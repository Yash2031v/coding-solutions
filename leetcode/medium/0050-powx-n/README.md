# Pow(x, n)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Implement pow(x, n), which calculates `x` raised to the power `n` (i.e., `xn`).

 

 **Example 1:** 

```
Input: x = 2.00000, n = 10
Output: 1024.00000

```

 **Example 2:** 

```
Input: x = 2.10000, n = 3
Output: 9.26100

```

 **Example 3:** 

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

```

 

 **Constraints:** 

- -100.0 < x < 100.0
- -231 <= n <= 231-1
- n is an integer.
- Either x is not zero or n > 0.
- -104 <= xn <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.7 MB  
**Submitted:** 2026-09-02T06:44:07.555Z  

```cpp
class Solution {
public:
    double myFun(double x,int n){
        if(n==0){
            return 1;
        }else{
            double temp = myFun(x,n/2);
            if(n%2==0){
                return temp*temp;
            }
            else{
                return x*temp*temp;
            }
        }
    }
    double myPow(double x, int n) {
        if(n>=0){
            return myFun(x,n);
        }
        else{
            double temp = myFun(x,-1*n);
            return 1/temp;
        }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/powx-n/)