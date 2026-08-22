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
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 118 MB (beats 82.09%)  
**Submitted:** 2026-08-22T09:20:35.157Z  

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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* cur = slow;
        while(cur!=NULL){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

        }
        ListNode* first = head;
        ListNode* second = prev;
        while(second!=NULL){
            if(second->val!=first->val){
                return false;
            }
            second = second->next;
            first = first->next;
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-linked-list/)