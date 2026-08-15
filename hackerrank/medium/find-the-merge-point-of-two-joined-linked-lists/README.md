# Cycle Detection

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool)

----

Given pointers to the head nodes of $2$ linked lists that merge together at some point, find the node where the two lists merge. The merge point is where both lists point to the same node, i.e. they reference the same memory location.  It is guaranteed that the two head nodes will be different, and neither will be NULL.  If the lists share a common node, return that node's $data$ value.  

**Note:**  After the merge point, both lists will share the same node pointers.  

**Example**  

In the diagram below, the two lists converge at Node `x`:

	[List #1] a--->b--->c
                         \
                          x--->y--->z--->NULL
                         /
         [List #2] p--->q

**Function Description**  

Complete the *findMergeNode* function in the editor below.  

*findMergeNode* has the following parameters:  

- *SinglyLinkedListNode pointer head1:* a reference to the head of the first list  
- *SinglyLinkedListNode pointer head2:* a reference to the head of the second list  

**Returns**  

- *int:*  the $data$ value of the node where the lists merge  


**Input Format**

*Do not read any input from stdin/console.*

The first line contains an integer $t$, the number of test cases.  

Each of the test cases is in the following format:  
The first line contains an integer, $index$, the node number where the merge will occur.  
The next line contains an integer, $list1_count$ that is the number of nodes in the first list.  
Each of the following $list1_count$ lines contains a $data$ value for a node.
The next line contains an integer, $list2_count$ that is the number of nodes in the second list.  
Each of the following $list2_count$ lines contains a $data$ value for a node.


**Constraints**

The lists will merge.  
$head1, head2 \ne null$.  
$head1 \ne head2$ . 


**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-15T10:18:00.240Z  

```cpp


// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* fast;
    SinglyLinkedListNode* slow;
    fast=head;
    slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }    
    }return false;
    
    
}


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem)