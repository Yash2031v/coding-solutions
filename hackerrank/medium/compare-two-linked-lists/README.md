# Compare two linked lists

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

<sub>This challenge is part of a tutorial track by [MyCodeSchool](http://www.youtube.com/mycodeschool)</sub>

You’re given the pointer to the head nodes of two linked lists. Compare the data in the nodes of the linked lists to check if they are equal. If all data attributes are equal and the lists are the same length, return $1$.  Otherwise, return $0$.  

**Example**  

$llist1 = 1 \rightarrow 2 \rightarrow 3 \rightarrow NULL$  
$llist2 = 1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow NULL$  

The two lists have equal data attributes for the first $3$ nodes.  $llist2$ is longer, though, so the lists are not equal.  Return $0$.  

**Function Description**  

Complete the *compare_lists* function in the editor below.  

*compare_lists* has the following parameters:  

- *SinglyLinkedListNode llist1:*  a reference to the head of a list  
- *SinglyLinkedListNode llist2:*  a reference to the head of a list  

**Returns**  

- *int:*  return 1 if the lists are equal, or 0 otherwise

**Input Format**

The first line contains an integer $t$, the number of test cases.  

Each of the test cases has the following format:  
The first line contains an integer $n$, the number of nodes in the first linked list.  
Each of the next $n$ lines contains an integer, each a value for a data attribute.  
The next line contains an integer $m$, the number of nodes in the second linked list.  
Each of the next $m$ lines contains an integer, each a value for a data attribute.  


**Constraints**

- $ 1 \le t \le 10$  
- $ 1 \le n, m \le 1000$  
- $ 1 \le llist1[i], llist2[i] \le 1000$

**Output Format**

Compare the two linked lists and <code>return</code> 1 if the lists are equal. Otherwise, <code>return</code> 0. Do NOT print anything to stdout/console.

The output is handled by the code in the editor and it is as follows:  

For each test case, in a new line, print $1$ if the two lists are equal, else print $0$.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-15T14:14:16.919Z  

```cpp


// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {

        if (temp1->data != temp2->data) {
            return 0;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 == NULL && temp2 == NULL) {
        return 1;
    }

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/compare-two-linked-lists/problem)