# Delete a Node

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool) and is accompanied by a video lesson.</sub>

Given a pointer to the head of a singly-linked list, print each $data$ value from the reversed list.  If the given list is empty, do not print anything.

**Example**  

$head*$ refers to the linked list with $data$ values $1 \rightarrow 2 \rightarrow 3 \rightarrow NULL$  

Print the following:  
`
3  
2  
1  
`

**Function Description**  

Complete the *reversePrint* function in the editor below.  

*reversePrint* has the following parameters:  

- *SinglyLinkedListNode pointer head:*  a reference to the head of the list

**Prints**  

The $data$ values of each node in the reversed list.  


**Input Format**

The first line of input contains $t$, the number of test cases.  

The input of each test case is as follows:  

- The first line contains an integer $n$, the number of elements in the list.  
- Each of the next *n* lines contains a data element for a list node.

**Constraints**

- $1 \le n \le 1000$  
- $1 \le list[i] \le 1000$, where $list[i]$ is the $i^{th}$ element in the list.  

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-15T10:46:20.243Z  

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
    if (position == 0) {
        SinglyLinkedListNode* temp = llist;
        llist = llist->next;
        delete temp;
        return llist;
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

[View on HackerRank](https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem)