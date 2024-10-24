class MyStack {
public:

    /* Method 1: Two queues. push O(1) and pop O(n) 

    queue<int> q1;
    queue<int> q2;

    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        q1.push(x);
    }
    
    int pop() 
    {
        if(q1.empty())
            return -1;
        
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int top_element = q1.front();
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return top_element;
    }
    
    int top() 
    {
        if(q1.empty())
            return -1;
        
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int top_element = q1.front();
        q2.push(q1.front()); // Don't forget to push back the last element
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return top_element;
    }
    
    bool empty() 
    {
        if(q1.empty())
            return true;

        return false;    
    }

    */

    /* Method 2: Two queues. Push O(n) and Pop is O(1) 

    queue<int> q1;
    queue<int> q2;

    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        q2.push(x);

        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    int pop() 
    {
        if(q1.empty())
            return -1;

        int top_element = q1.front();
        q1.pop();
        return top_element;   
    }
    
    int top() 
    {
        if(q1.empty())
            return -1;
        
        return q1.front();
    }
    
    bool empty() 
    {
        return q1.empty();
    }

    */

    /* Method 3: Using Single Queue. Push O(n) and Pop O(1) */

    queue<int> q;

    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        q.push(x);
        int size = q.size();

        for(int i = 0; i < size-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() 
    {
        if(q.empty())
            return -1;
        
        int top_element = q.front();
        q.pop();
        return top_element;    
    }
    
    int top() 
    {
        if(q.empty())
            return -1;
        
        return q.front();
    }
    
    bool empty() 
    {
        return q.empty();
    }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */