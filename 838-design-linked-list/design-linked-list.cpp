class MyListNode {
public:
    int val;
    MyListNode* prev;
    MyListNode* next;
    MyListNode(): val(0), prev(NULL), next(NULL) {}
    MyListNode(int value) : val(value), prev(NULL), next(NULL) {}
    MyListNode(int value, MyListNode *p, MyListNode* n): val(value), prev(p), next(n) {}
};

class MyLinkedList {
public:
    int size;
    MyListNode* head;
    MyListNode* tail;

    MyLinkedList() {
        head = new MyListNode(-2, NULL, NULL);
        tail = new MyListNode(-1, head, NULL);
        head->next = tail;
        size = 0;
    }

    MyListNode* getNodeFromIndex(int index) {
        if(index < 0 || index >= size)
            return NULL;

        MyListNode *current = NULL;

        if(index < size/2) {
            current = head->next;

            for(int i = 0; i < index; i++) {
                current = current->next;
            }
        } else {
            current = tail->prev;

            for(int i = size-1; i > index; i--) {
                current = current->prev;
            }
        }
        return current;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;

        MyListNode* current = getNodeFromIndex(index);
        return (current ? current->val: -1);
    }
    
    void addAtHead(int val) {
        MyListNode* newNode = new MyListNode(val);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        MyListNode* newNode = new MyListNode(val);
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == size) {  // Adding at the tail
            addAtTail(val);
            return;
        }

        MyListNode* current = getNodeFromIndex(index);
        if (!current) return;  // If current is NULL, exit

        MyListNode* newNode = new MyListNode(val);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        MyListNode* current = getNodeFromIndex(index);
        if (!current) return;  // If current is NULL, exit

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
};



/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */