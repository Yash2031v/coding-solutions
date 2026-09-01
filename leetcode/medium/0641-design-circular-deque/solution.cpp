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