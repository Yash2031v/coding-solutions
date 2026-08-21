# Remove Linked List Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return  *the new head*.

 

 **Example 1:** 

```
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

```

 **Example 2:** 

```
Input: head = [], val = 1
Output: []

```

 **Example 3:** 

```
Input: head = [7,7,7,7], val = 7
Output: []

```

 

 **Constraints:** 

- The number of nodes in the list is in the range [0, 104].
- 1 <= Node.val <= 50
- 0 <= val <= 50

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 5.10%)  
**Memory:** 20.4 MB (beats 12.49%)  
**Submitted:** 2026-08-21T16:26:55.958Z  

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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            ListNode* del=head;
            head=del->next;
            delete del;
        }
        ListNode* temp = head;
        ListNode* temp2;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->val==val){
                temp2=temp->next;
                temp->next=temp->next->next;
                delete temp2;
            }
            else{
                temp=temp->next;
            }
            
        }return head;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/remove-linked-list-elements/)