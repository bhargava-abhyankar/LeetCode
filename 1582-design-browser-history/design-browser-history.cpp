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

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */