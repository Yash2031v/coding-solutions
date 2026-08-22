# Add Two Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two  **non-empty**  linked lists representing two non-negative integers. The digits are stored in  **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

 **Example 1:** 

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

```

 **Example 2:** 

```
Input: l1 = [0], l2 = [0]
Output: [0]

```

 **Example 3:** 

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

```

 

 **Constraints:** 

- The number of nodes in each linked list is in the range [1, 100].
- 0 <= Node.val <= 9
- It is guaranteed that the list represents a number that does not have leading zeros.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 34.17%)  
**Memory:** 77.3 MB (beats 12.99%)  
**Submitted:** 2026-08-22T10:12:12.229Z  

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* add = new ListNode(0);
        ListNode* result = add;
        int carry = 0;
        while(l1!=NULL || l2!=NULL){
            int sum = 0 + carry;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;

            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;

            }
            
            carry=sum/10;
            sum=sum%10;
            add->next=new ListNode(sum);
            add = add->next;
            if(carry!=0){
                add->next=new ListNode(carry);
            }

        }return result->next;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/add-two-numbers/)