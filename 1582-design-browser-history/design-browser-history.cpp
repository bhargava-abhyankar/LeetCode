 /* Method 1 */

class BrowserHistory {
public:
    stack<string> history;
    stack<string> future;

    BrowserHistory(string homepage) 
    {
        history.push(homepage);
        future = stack<string>();
    }
    
    void visit(string url) 
    {
        history.push(url);
        future = stack<string>();
    }
    
    string back(int steps) 
    {
        while(history.size() > 1 && steps > 0) {     // history.size() > 1, this is ensure we dont move go back than homepage. !history.empty() will not work.
            future.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) 
    {
        while(!future.empty() && steps > 0) {
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};


/* Method 2:

class MyListNode {
public:
    string val;
    MyListNode *prev;
    MyListNode *next;
    MyListNode(): val(""), prev(NULL), next(NULL) {}
    MyListNode(string value): val(value), prev(NULL), next(NULL) {}
    MyListNode(string value, MyListNode *p, MyListNode *n): val(value), prev(p), next(n) {} 
};

class BrowserHistory {
public:
    MyListNode *head;
    MyListNode *current;

    BrowserHistory(string homepage) 
    {
        head = new MyListNode(homepage, NULL, NULL);
        current = head;
    }
    
    void visit(string url) 
    {
        MyListNode *traverse = current->next;

        while(traverse) {
            MyListNode *to_delete = traverse;
            traverse = traverse->next;
            delete(to_delete);
        }

        MyListNode *new_node = new MyListNode(url, current, NULL);
        current->next = new_node;
        current = new_node;
    }
    
    string back(int steps) 
    {
        while(current->prev && steps > 0) {
            current = current->prev;
            steps--;
        }
        return current->val;    
    }
    
    string forward(int steps) 
    {
        while(current->next && steps > 0) {
            current = current->next;
            steps--;
        }
        return current->val;
    }
};

*/

/* Method 3

class BrowserHistory {
public:
    vector<string> history;
    int current;
    int last;

    BrowserHistory(string homepage) 
    {
        history.push_back(homepage);
        current = 0;
        last = 0;
    }
    
    void visit(string url) 
    {
        current = current + 1;

        if(current < (history.size())) {
            history[current] = url;

        } else {
            history.push_back(url);
        }

        last = current;
    }
    
    string back(int steps) 
    {
        (current - steps) > 0 ? (current = (current - steps)):(current = 0);
        return history[current];
    }
    
    string forward(int steps) 
    {
        (current + steps) < last ? (current = current + steps): (current = last);
        return history[current];
    }

};

*/



/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */