# Delete duplicate-value nodes from a sorted linked list

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool)</sub>


You are given the pointer to the head node of a sorted linked list, where the data in the nodes is in ascending order. Delete nodes and return a sorted list with each distinct value in the original list. The given head pointer may be null indicating that the list is empty.  

**Example**  

$head$ refers to the first node in the list $1 \rightarrow 2 \rightarrow 2 \rightarrow 3 \rightarrow 3 \rightarrow 3 \rightarrow 3 \rightarrow NULL$.  

Remove 1 of the $2$ data values and return $head$ pointing to the revised list $1 \rightarrow 2 \rightarrow 3 \rightarrow NULL$.  

**Function Description**  

Complete the *removeDuplicates* function in the editor below.  

*removeDuplicates* has the following parameter:  

- *SinglyLinkedListNode pointer head:* a reference to the head of the list  

**Returns**  

- *SinglyLinkedListNode pointer:* a reference to the head of the revised list  

**Input Format**

The first line contains an integer $t$, the number of test cases.


The format for each test case is as follows:  

The first line contains an integer $n$, the number of elements in the linked list.  
Each of the next $n$ lines contains an integer, the $data$ value for each of the elements of the linked list.

**Constraints**

- $ 1 \le t \le 10$  
- $ 1 \le n \le 1000$
- $ 1 \le list[i] \le 1000$


**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-23T16:17:25.875Z  

```cpp


/*
 * Complete the 'removeDuplicates' function below.
 *
 * The( function is expected to return an INTEGER_SINGLY_LINKED_LIST.
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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(llist==NULL){
        return llist;
    }
    SinglyLinkedListNode* temp = llist;
    while(temp->next!=NULL){
        if(temp->data == temp->next->data){
            temp->next=temp->next->next;
        }else{
        temp=temp->next;
        }
    }
    return llist;
}


```

---

[View on HackerRank](https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem)