# Decimal to binary

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a decimal integer  **n**, convert it and return its binary equivalent as a string.

 **Examples :** 

```
Input: n = 12
Output: 1100
Explanation: The binary representation of 12 is "1100", since 12 = 1×23 + 1×22 + 0×21 + 0×20
```

```
Input: n = 33
Output: 100001
Explanation: The binary representation of 33 is "100001", since 33 = 1×25 + 0×24 + 0×23 + 0×22 + 0×21 + 1×20

```

**Constraints:
**1 ≤ n ≤ 231 - 1

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-07T06:17:56.108Z  

```cpp
class Solution {
  public:
    string decToBinary(int n) {
        // code here
        if(n==0){
            return "";
        }else{
            return decToBinary(n/2)+to_string(n%2);
        }
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/decimal-to-binary-1587115620/1)