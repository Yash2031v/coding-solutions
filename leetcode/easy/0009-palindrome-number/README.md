# Palindrome Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an integer `x`, return `true` if `x` is a  **palindrome**, and `false` otherwise.

 

 **Example 1:** 

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

```

 **Example 2:** 

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

```

 **Example 3:** 

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

```

 

 **Constraints:** 

- -231 <= x <= 231 - 1

 

 **Follow up:**  Could you solve it without converting the integer to a string?

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 30.51%)  
**Memory:** 8.5 MB (beats 92.15%)  
**Submitted:** 2026-09-01T10:02:31.557Z  

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        int temp = x;
        long long sum = 0;
        while(temp>0){
            sum = sum*10 + temp%10;
            temp = temp/10;   
        }
        if(x==sum){
            return true;
        }
        else{
            return false;
        }
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-number/)