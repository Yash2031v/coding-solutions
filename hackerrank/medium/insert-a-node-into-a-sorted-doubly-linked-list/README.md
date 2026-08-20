# Inserting a Node Into a Sorted Doubly Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a reference to the head of a doubly-linked list and an integer, $data$, create a new *DoublyLinkedListNode* object having data value $data$ and insert it at the proper location to maintain the sort.  

**Example**  

$head$ refers to the list $1 \leftrightarrow 2 \leftrightarrow 4 \rightarrow NULL$  
$data = 3$  

Return a reference to the new list: $1 \leftrightarrow 2 \leftrightarrow 3 \leftrightarrow 4 \rightarrow NULL$.

**Function Description**

Complete the *sortedInsert* function in the editor below.  

sortedInsert has two parameters:

- *DoublyLinkedListNode pointer head*: a reference to the head of a doubly-linked list 

- *int data*: An integer denoting the value of the $data$ field for the *DoublyLinkedListNode* you must insert into the list.

**Returns**  

- *DoublyLinkedListNode pointer:* a reference to the head of the list  

**Note:** Recall that an empty list (i.e., where $head = \texttt{NULL}$) and a list with one element *are* sorted lists. 

**Input Format**

The first line contains an integer $t$, the number of test cases.

Each of the test case is in the following format:  

- The first line contains an integer $n$, the number of elements in the linked list.  
- Each of the next $n$ lines contains an integer, the *data* for each node of the linked list.  
- The last line contains an integer, $data$, which needs to be inserted into the sorted doubly-linked list.

**Constraints**

- $1 \le t \le 10$  
- $1 \le n \le 1000$  
- $1 \le DoublyLinkedListNode.data \le 1000$

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-20T04:43:31.789Z  

```cpp


/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
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

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* node = new DoublyLinkedListNode(data);

    // Empty list
    if (llist == NULL) {
        return node;
    }

    // Insert at beginning
    if (data <= llist->data) {
        node->next = llist;
        llist->prev = node;
        return node;
    }

    DoublyLinkedListNode* temp = llist;

    // Find position
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    // Insert node after temp
    node->next = temp->next;
    node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = node;
    }

    temp->next = node;

    return llist;
}


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem)