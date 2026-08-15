# Reverse a linked list

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool) and is accompanied by a video lesson.</sub>

Given the pointer to the head node of a linked list, change the <code>next</code> pointers of the nodes so that their order is reversed. The head pointer given may be null meaning that the initial list is empty.  

**Example**  
$head$ references the list $1 \rightarrow 2 \rightarrow 3 \rightarrow NULL$  

Manipulate the $next$ pointers of each node in place and return $head$, now referencing the head of the list $3 \rightarrow 2 \rightarrow 1 \rightarrow NULL$.  

**Function Description**  

Complete the *reverse* function in the editor below.  

*reverse* has the following parameter:  

- *SinglyLinkedListNode pointer head:*  a reference to the head of a list  

**Returns**  

- *SinglyLinkedListNode pointer:*  a reference to the head of the reversed list  
 

**Input Format**

The first line contains an integer $t$, the number of test cases.  

Each test case has the following format:  

The first line contains an integer $n$, the number of elements in the linked list.  
Each of the next $n$ lines contains an integer, the $data$ values of the elements in the linked list.  

**Constraints**

- $1 \le t \le 10$  
- $1 \le n \le 1000$  
- $1 \le list[i] \le 1000$, where $list[i]$ is the $i^{th}$ element in the list.


**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-15T13:47:46.678Z  

```cpp


/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* Next;
    while(current!=NULL){
        Next=current->next;
        current->next=prev;
        prev = current;
        current=Next;
        
    }
    return prev;
    
}


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/reverse-a-linked-list/problem)