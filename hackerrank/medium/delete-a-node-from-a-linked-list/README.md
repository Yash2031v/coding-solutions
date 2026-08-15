# Delete a Node

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool) and is accompanied by a video lesson.</sub>


Delete the node at a given position in a linked list and return a reference to the head node. The head is at position 0. The list may be empty after you delete the node. In that case, return a null value. 

**Example**  

$llist = 0 \rightarrow 1 \rightarrow 2 \rightarrow 3$  
$position=2$  

After removing the node at position $2$, $llist' = 0 \rightarrow 1 \rightarrow 3$.  

**Function Description**  

Complete the *deleteNode* function in the editor below.  

*deleteNode* has the following parameters:  
- *SinglyLinkedListNode pointer llist:*  a reference to the head node in the list  
- *int position:*  the position of the node to remove

**Returns**  
- *SinglyLinkedListNode pointer:* a reference to the head of the modified list  

**Input Format**

The first line of input contains an integer $n$, the number of elements in the linked list.  
Each of the next $n$ lines contains an integer, the node data values in order.  
The last line contains an integer, $position$, the position of the node to delete.  


**Constraints**

- $1 \le n \le 1000$  
- $1 \le list[i] \le 1000$, where $list[i]$ is the $i^{th}$ element of the linked list.

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-15T10:43:44.231Z  

```cpp


/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    int count=1;
    SinglyLinkedListNode* temp = llist;
    if(llist==NULL){
        return NULL;
    }
    while(count!=position){
        temp=temp->next;
        count++;
    }
    SinglyLinkedListNode* temp1 = temp->next;
    temp->next=temp->next->next;
    free(temp1);
    return llist;
    
}


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem)