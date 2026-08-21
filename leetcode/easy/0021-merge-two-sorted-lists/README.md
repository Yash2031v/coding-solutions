# Merge Two Sorted Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one  **sorted**  list. The list should be made by splicing together the nodes of the first two lists.

Return  *the head of the merged linked list*.

 

 **Example 1:** 

```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

```

 **Example 2:** 

```
Input: list1 = [], list2 = []
Output: []

```

 **Example 3:** 

```
Input: list1 = [], list2 = [0]
Output: [0]

```

 

 **Constraints:** 

- The number of nodes in both lists is in the range [0, 50].
- -100 <= Node.val <= 100
- Both list1 and list2 are sorted in non-decreasing order.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 19.3 MB (beats 88.16%)  
**Submitted:** 2026-08-21T16:00:06.025Z  

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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1==NULL ||head2==NULL){
            return head1 == NULL ? head2 : head1;
        }
        if(head1->val<=head2->val){
            head1->next = mergeTwoLists(head1->next,head2);
            return head1;
        }
        else{
            head2->next = mergeTwoLists(head1,head2->next);
            return head2;
        }
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/merge-two-sorted-lists/)