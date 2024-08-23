class MyCircularQueue {
public:
    int *my_queue;
    int cur_position;
    int size;
    int count;

    MyCircularQueue(int k) {
        my_queue = new int[k];
        cur_position = 0;
        size = k;
        count = 0;
    }
    
    bool enQueue(int value) 
    {
        if(isFull()) {
            return false;
        }

        my_queue[(cur_position + count) % size] = value;
        count = count + 1;
        return true;   
    }
    
    bool deQueue() 
    {
        if(isEmpty()) {
            return false;
        }

        cur_position = (cur_position + 1) % size;
        count = count - 1;
        return true;
    }
    
    int Front() 
    {
        if(isEmpty()) {
            return -1;
        }

        return my_queue[cur_position];    
    }
    
    int Rear() 
    {
        if(isEmpty())
            return -1;

        int tailIndex = (cur_position + count - 1) % size;
        return my_queue[tailIndex];
    }
    
    bool isEmpty() 
    {
        if(count == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() 
    {
        if(count == size)
            return true;
        else
            return false;
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