class MyCircularQueue {
public:
    vector<int>item;
    int rear;
    int front;
    int SIZE;
    MyCircularQueue(int k) {
        item.resize(k+1);
        SIZE = k+1;
        rear = SIZE-1;
        front = SIZE-1;

    }
    
    bool enQueue(int value) {
        if((rear+1)%SIZE == front)
            return false;
                
        rear = (rear+1)%SIZE;
        item[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(rear==front)
             return false;
        
        front = (front+1)%SIZE;
        return true;
    }
    
    int Front() {
        if(rear==front){
            return -1;
        }
        int f;
        f = (front+1)%SIZE;
        return item[f];
    }
    
    int Rear() {
        if(rear==front){
            return -1;
        }
        return item[rear];
    }
    
    bool isEmpty() {
        if(rear==front){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if((rear+1)%SIZE==front)
        return true;
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */