# Design Circular Deque

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Design your implementation of the circular double-ended queue (deque).

Implement the `MyCircularDeque` class:

- MyCircularDeque(int k) Initializes the deque with a maximum size of k.
- boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
- boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
- boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
- boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
- int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
- int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
- boolean isEmpty() Returns true if the deque is empty, or false otherwise.
- boolean isFull() Returns true if the deque is full, or false otherwise.

 

 **Example 1:** 

```
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4

```

 

 **Constraints:** 

- 1 <= k <= 1000
- 0 <= value <= 1000
- At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 24.6 MB (beats 5.40%)  
**Submitted:** 2026-09-01T04:58:39.090Z  

```cpp
struct node {
    int data;
    node *prev, *next;
};

class MyCircularDeque {
public:
    int SIZE;
    int current;
    node *Front, *Rear;

    MyCircularDeque(int k) {
        Front = NULL;
        Rear = NULL;
        SIZE = k;
        current = 0;
    }

    bool insertFront(int value) {
        if (current == SIZE)
            return false;

        node *p = new node;
        p->data = value;
        p->prev = NULL;
        p->next = Front;

        if (Front != NULL)
            Front->prev = p;
        else
            Rear = p;

        Front = p;
        current++;

        return true;
    }

    bool insertLast(int value) {
        if (current == SIZE)
            return false;

        node *p = new node;
        p->data = value;
        p->next = NULL;
        p->prev = Rear;

        if (Rear != NULL)
            Rear->next = p;
        else
            Front = p;

        Rear = p;
        current++;

        return true;
    }

    bool deleteFront() {
        if (Front == NULL)
            return false;

        node *p = Front;
        Front = Front->next;

        delete p;

        if (Front != NULL)
            Front->prev = NULL;
        else
            Rear = NULL;

        current--;

        return true;
    }

    bool deleteLast() {
        if (Rear == NULL)
            return false;

        node *p = Rear;
        Rear = Rear->prev;

        delete p;

        if (Rear != NULL)
            Rear->next = NULL;
        else
            Front = NULL;

        current--;

        return true;
    }

    int getFront() {
        if (current == 0)
            return -1;

        return Front->data;
    }

    int getRear() {
        if (current == 0)
            return -1;

        return Rear->data;
    }

    bool isEmpty() {
        return current == 0;
    }

    bool isFull() {
        return current == SIZE;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/design-circular-deque/)