# Palindrome Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `head` of a singly linked list, return `true` *if it is a  **palindrome**  or* `false` *otherwise*.

 

 **Example 1:** 

```
Input: head = [1,2,2,1]
Output: true

```

 **Example 2:** 

```
Input: head = [1,2]
Output: false

```

 

 **Constraints:** 

- The number of nodes in the list is in the range [1, 105].
- 0 <= Node.val <= 9

 

 **Follow up:**  Could you do it in `O(n)` time and `O(1)` space?

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 58.41%)  
**Memory:** 132 MB (beats 13.11%)  
**Submitted:** 2026-08-22T09:09:17.428Z  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>n;
        ListNode* temp = head;
        while(temp!=NULL){
            n.push_back(temp->val);
            temp=temp->next;
        }
        
        int r = n.size()-1;
        int f = 0;
        while(r>=f){
            if(n[r]!=n[f]){
                return false;
            }
            r--;
            f++;
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-linked-list/)