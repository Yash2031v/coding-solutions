# Insert a node at a specific position in a linked list

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool) and is accompanied by a video lesson.</sub>

Given a pointer to the head node of a linked list and an integer to insert at a certain position, create a new node with the given integer as its $data$ attribute, insert this node at the desired position, and return the head node.

A position of 0 indicates the head, a position of 1 indicates one node away from the head, and so on. The head pointer given may be null, meaning that the initial list is empty.    

**Example**  
$head$ refers to the first node in the list $1 \rightarrow 2 \rightarrow 3$  
$data = 4$  
$position = 2$  

Insert a node at position $2$ with $data = 4$.  The new list is $1 \rightarrow 2 \rightarrow 4 \rightarrow 3$

**Function Description**  
Complete the function $insertNodeAtPosition$ with the following parameters:

-  $SinglyLinkedListNode\ pointer\ llist$: a reference to the head of the list
-  $data$: an integer value to insert as data in the new node
-  $position$: an integer position to insert the new node, zero-based indexing  

**Returns**  

-  $SinglyLinkedListNode\ pointer$: a reference to the head of the revised list  

**Input Format**

The first line contains an integer $n$, the number of elements in the linked list.  
Each of the next $n$ lines contains an integer SinglyLinkedListNode[i].data.  
The next line contains an integer $data$, the data of the node that is to be inserted.  
The last line contains an integer $position$.



**Constraints**

- $ 1 \le n \le 1000$  
- $ 1 \le SinglyLinkedListNode[i].data \le 1000$, where $SinglyLinkedListNode[i]$ is the $i^{th}$ element of the linked list.  
- $ 0 \le position \le n$.  


**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-15T10:37:38.698Z  

```cpp


/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* new_node = new SinglyLinkedListNode(data);
    int count=1;
    SinglyLinkedListNode* temp = llist;
    while(count!=position){
        temp=temp->next;
        count++;
    }
    SinglyLinkedListNode* temp1 = temp->next;
    temp->next=new_node;
    new_node->next=temp1;
    return llist;
    
    
}


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem)