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
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.8 MB (beats 88.89%)  
**Submitted:** 2026-09-11T17:40:07.859Z  

```cpp
class Solution {
public:
    bool check(char a, char b){
        if((a=='(' && b==')') || (a=='{' && b=='}') ||(a=='[' && b==']')){
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
                if (item.empty()) {
                    return false;
                }
                if(check(item.top(),s[n])){
                    item.pop();
                }
                else{
                    return false;
                }
            
            }
            n++;
            
        }
        if(!item.empty()){
            return false;
        }
        return true;
    }

};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parentheses/)