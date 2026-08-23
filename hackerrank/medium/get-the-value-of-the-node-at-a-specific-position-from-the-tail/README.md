# Get Node Value

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool)</sub>

Given a pointer to the head of a linked list and a specific position, determine the data value at that position. Count backwards from the tail node.  The tail is at postion 0, its parent is at 1 and so on.

**Example**  
$head$ refers to $3 \rightarrow 2 \rightarrow 1 \rightarrow 0 \rightarrow NULL$  
$positionFromTail = 2$  

Each of the data values matches its distance from the tail.  The value $2$ is at the desired position.  

**Function Description**  

Complete the *getNode* function in the editor below.  

*getNode* has the following parameters:  

- *SinglyLinkedListNode pointer head:* refers to the head of the list  
- *int positionFromTail:* the item to retrieve  

**Returns**  

- *int:* the value at the desired position  

**Input Format**

The first line contains an integer $t$, the number of test cases.  

Each test case has the following format:  
The first line contains an integer $n$, the number of elements in the linked list.  
The next $n$ lines contains an integer, the data value for an element of the linked list.  
The last line contains an integer $positionFromTail$, the position from the tail to retrieve the value of.   

**Constraints**

- $ 1 \le t \le 10$  
- $ 1 \le n, m \le 1000$  
- $ 1 \le list[i] \le 1000$, where $list[i]$ is the $i^{th}$ element of the linked list.  
- $ 0 \le positionFromTail \lt n$

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-23T16:06:51.016Z  

```cpp


/*
 * Complete the 'getNode' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER positionFromTail
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

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    dummy->next = llist;
    SinglyLinkedListNode* a = dummy;
    SinglyLinkedListNode* b = dummy;
    for(int i=0;i< positionFromTail;i++){
        b = b->next;
    }
    while(b->next!=NULL){
        a=a->next;
        b=b->next;
    }
    int r = a->data;
    return r;
}


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem)