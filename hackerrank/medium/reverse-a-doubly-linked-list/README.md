# Reverse a doubly linked list

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool)</sub>


Given the pointer to the head node of a doubly linked list, reverse the order of the nodes in place. That is, change the *next* and *prev* pointers of the nodes so that the direction of the list is reversed. Return a reference to the head node of the reversed list. 

**Note:** The head node might be NULL to indicate that the list is empty.  

**Function Description**

Complete the _reverse_ function in the editor below.  

reverse has the following parameter(s):

- *DoublyLinkedListNode head*: a reference to the head of a DoublyLinkedList  

Returns  
- *DoublyLinkedListNode*: a reference to the head of the reversed list  

**Input Format**

The first line contains an integer $t$, the number of test cases.  

Each test case is of the following format:

-  The first line contains an integer $n$, the number of elements in the linked list.  
-  The next $n$ lines contain an integer each denoting an element of the linked list.

**Constraints**

- $1 \le t \le 10$  
- $0 \le n \le 1000$  
- $0 \le DoublyLinkedListNode.data \le 1000$   

**Output Format**

Return a reference to the head of your reversed list.  The provided code will print the reverse array as a one line of space-separated integers for each test case.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-28T15:21:31.413Z  

```cpp


/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if (llist == NULL)
        return NULL;

    DoublyLinkedListNode* curr = llist;

    while (curr != NULL) {
        swap(curr->next, curr->prev);
        
        if (curr->prev == NULL)
            return curr;

        curr = curr->prev;
    }

    return llist;
}  


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem)