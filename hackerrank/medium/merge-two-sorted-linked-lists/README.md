# Merge two sorted linked lists

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool)</sub>

Given pointers to the heads of two sorted linked lists, merge them into a single, sorted linked list. Either head pointer may be null meaning that the corresponding list is empty.

**Example**  
$headA$ refers to $1 \rightarrow 3 \rightarrow 7 \rightarrow NULL$  
$headB$ refers to $1 \rightarrow 2 \rightarrow NULL$  

The new list is $1 \rightarrow 1 \rightarrow 2 \rightarrow 3 \rightarrow 7 \rightarrow NULL$  

**Function Description**  

Complete the *mergeLists* function in the editor below.  

*mergeLists* has the following parameters:  

- *SinglyLinkedListNode pointer headA:* a reference to the head of a list  
- *SinglyLinkedListNode pointer headB:* a reference to the head of a list  

**Returns**  

- *SinglyLinkedListNode pointer:* a reference to the head of the merged list  


**Input Format**

The first line contains an integer $t$, the number of test cases.  

The format for each test case is as follows:  

The first line contains an integer $n$, the length of the first linked list.  
The next $n$ lines contain an integer each, the elements of the linked list.  
The next line contains an integer $m$, the length of the second linked list.  
The next $m$ lines contain an integer each, the elements of the second linked list.  

**Constraints**

- $1 \le t \le 10$  
- $1 \le n, m \le 1000$
- $1 \le list[i] \le 1000$, where $list[i]$ is the $i^{th}$ element of the list.

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-22T15:25:34.605Z  

```cpp


// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1==NULL|| head2==NULL){
        return head1==NULL? head2:head1;
    }
    if(head1->data<=head2->data){
        head1->next = mergeLists(head1->next,head2);
        return head1;
    }
    else{
        head2->next = mergeLists(head1,head2->next);
        return head2;
    }
    

        
    
    

}


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem)