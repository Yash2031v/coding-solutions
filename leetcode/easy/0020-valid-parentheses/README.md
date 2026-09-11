# Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

 

 **Example 1:** 

 **Input:**  s = "()"

 **Output:**  true

 **Example 2:** 

 **Input:**  s = "()[]{}"

 **Output:**  true

 **Example 3:** 

 **Input:**  s = "(]"

 **Output:**  false

 **Example 4:** 

 **Input:**  s = "([])"

 **Output:**  true

 **Example 5:** 

 **Input:**  s = "([)]"

 **Output:**  false

 

 **Constraints:** 

- 1 <= s.length <= 104
- s consists of parentheses only '()[]{}'.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.9 MB  
**Submitted:** 2026-09-11T17:34:37.088Z  

```cpp
class Solution {
public:
    bool check(char a, char b){
        if(a=='(' && b==')'){
            return true; 
        }
        if(a=='{' && b=='}'){
            return true; 
        }
        if(a=='[' && b==']'){
            return true; 
        }
        return false;
    }
    bool isValid(string s) {
        stack<char>item;
        int n = 0;
        if(s.size()%2!=0){
            return false;
        }
        while(n<s.size()){
            if(s[n]=='(' || s[n]=='[' || s[n]=='{'){
                item.push(s[n]);
            }
            
            else{
                if(check(item.top(),s[n])){
                    item.pop();
                }
                else{
                    return false;
                }
            
            }
            n++;
            
        }
        return true;
    }

};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parentheses/)