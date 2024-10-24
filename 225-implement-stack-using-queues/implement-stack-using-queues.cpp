class MyStack {
public:

    /*Approach 1: Two queues. push O(1) and pop O(n) */

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
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */