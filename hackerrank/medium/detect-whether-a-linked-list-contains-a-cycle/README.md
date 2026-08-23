# Cycle Detection

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A linked list is said to contain a *cycle* if any node is visited more than once while traversing the list.  Given a pointer to the head of a linked list, determine if it contains a cycle.  If it does, return $1$.  Otherwise, return $0$.  

**Example**  

$head$ refers to the list of nodes $1 \rightarrow 2 \rightarrow 3  \rightarrow NULL$  

The numbers shown are the node numbers, not their data values.  There is no cycle in this list so return $0$.  

$head$ refers to the list of nodes $1 \rightarrow 2 \rightarrow 3 \rightarrow 1 \rightarrow NULL$  

There is a cycle where node 3 points back to node 1, so return $1$.  

**Function Description**  

Complete the *has_cycle* function in the editor below.  

It has the following parameter:  

- *SinglyLinkedListNode pointer head:*  a reference to the head of the list  

**Returns**  

- *int:*  $1$ if there is a cycle or $0$ if there is not  


**Note:** If the list is empty, $head$ will be *null*.

**Input Format**

The code stub reads from stdin and passes the appropriate argument to your function. The custom test cases format will not be described for this question due to its complexity.  Expand the section for the main function and review the code if you would like to figure out how to create a custom case.  

**Constraints**

- $0 \le \textit{ list size } \le 1000$

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-23T16:17:49.806Z  

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

[View on HackerRank](https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem)