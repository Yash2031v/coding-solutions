# Roman to Integer

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9. 
- X can be placed before L (50) and C (100) to make 40 and 90. 
- C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

 

 **Example 1:** 

```
Input: s = "III"
Output: 3
Explanation: III = 3.

```

 **Example 2:** 

```
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

```

 **Example 3:** 

```
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

```

 

 **Constraints:** 

- 1 <= s.length <= 15
- s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
- It is guaranteed that s is a valid roman numeral in the range [1, 3999].

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10 MB (beats 85.76%)  
**Submitted:** 2026-09-27T15:38:27.354Z  

```cpp
class Solution {
public:
    int ToNumsF(char ch){
        if(ch=='I'){
            return 4;
        }
        if(ch=='X'){
            return 40;
        }
        if(ch=='C'){
            return 400;
        }
        return 0;
    }
    int ToNums(char ch){
        if(ch=='I'){
            return 9;
        }
        if(ch=='C'){
            return 900;
        }
        if(ch=='X'){
            return 90;
        }
        return 0;
    }
    int ToNum(char ch){
        if(ch=='I'){
            return 1;
        }
        if(ch=='V'){
            return 5;
        }
        if(ch=='X'){
            return 10;
        }
        if(ch=='L'){
            return 50;
        }
        if(ch=='C'){
            return 100;
        }
        if(ch=='D'){
            return 500;
        }
        if(ch=='M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(ToNum(s[i])<ToNum(s[i+1])){
                if(ToNum(s[i+1])==5||ToNum(s[i+1])==50||ToNum(s[i+1])==500){
                    sum = sum + ToNumsF(s[i]);
                    i++;
                }
                else{
                    sum = sum + ToNums(s[i]);
                    i++;
                }
            }
            else{
                sum = sum + ToNum(s[i]);
            }
        }
        return sum;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/roman-to-integer/)