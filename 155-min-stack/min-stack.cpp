class MinStack {
public:

    /* Method 1: Maintaining min in each element

    stack<pair<int, int>> st;

    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(st.empty()) {
            st.push({val, val});
            return;
        }

        if(val < st.top().second)
            st.push({val, val});
        else
            st.push({val, st.top().second});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

    */

    /* Method 2: Using two stacks 

    stack<int> regular_stack;
    stack<int> min_stack;

    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(min_stack.empty() || val <= min_stack.top())
            min_stack.push(val);

        regular_stack.push(val);
    }
    
    void pop() {
        if(regular_stack.top() == min_stack.top())
            min_stack.pop();

        regular_stack.pop();
    }
    
    int top() {
        return regular_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }

    */

    /* Method 3: Improvisation to two stack method */

    stack<int> regular_stack;
    stack<pair<int, int>> min_stack; 

    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(min_stack.empty() || val < min_stack.top().first)
            min_stack.push({val, 1});
        else if (val == min_stack.top().first)
            min_stack.top().second++;

        regular_stack.push(val);
    }
    
    void pop() {
        if(min_stack.top().first == regular_stack.top())
            min_stack.top().second--;

        if(min_stack.top().second == 0)
            min_stack.pop();
        
        regular_stack.pop();
    }
    
    int top() {
        return regular_stack.top();
    }
    
    int getMin() {
        return min_stack.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */