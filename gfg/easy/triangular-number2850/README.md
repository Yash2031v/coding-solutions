# Triangular Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a number  **n**, check whether it is a triangular number or not. Return  **1**  if it is a triangular number, otherwise return **0**.

 **Note:**  A number is a  **triangular number**  if it can be represented in the form of a triangular grid of points, where each row contains as many points as its row number. The first few triangular numbers are 1, 3 (1+2), 6 (1+2+3), 10 (1+2+3+4), and so on.

 **Examples:** 

```
Input: n = 55
Output: 1
Explanation: 55 is a triangular number. It can be represented in 10 rows.
```

```
Input: n = 56
Output: 0
Explanation: 56 is not a triangular number. 
```

 **Constraints:** 
1<= n <=106

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-07T06:35:36.064Z  

```cpp
class Solution {
  public:
    int good(int n,int i){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        return good(n-i,i+1);
    }
    int isTriangular(int n) {
        // code here
        int i=1;
        return good(n,i);
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/triangular-number2850/1)