class LRUCache {
public:

    /* Approach: First and foremost dont use dummy head. Write helper functions first. Delete of a node in doubly linked list by taking care of last node variable
                 then write a function to add a node at head. usual take care of head null case and last node = head. Now its simple to write get and put. Just
                 take care of hash table deletion, there to remove the element from hash_table, u need to pass iterator.
                
                 In put, u need to handle value updation also. get is as name implies. Anything that is accessed will become used and come to head of list. So

                 In both put and get. two checks. element is present or not.

                 put: If element is present,  delete the node, remove hash entry, add the node and update the hash entry.
                      If not present, then Two checks, max limit reached or not. if max is reached, then delete hash entry 
                      of last node, delete last node and add new node, add hash entry if max not reached, simply add node, increment the counter and 
                      update hash entry 
                 get: Check if key is present, if present, delete the node, remove hash entry, add the node and update the hash entry.
    */
    
    struct ListNode {
        int val;
        int key;
        ListNode *next;
        ListNode *prev;
        ListNode() : val(0), key(0), next(NULL), prev(NULL) {}
        ListNode(int value, int key_val) : val(value), key(key_val), next(NULL), prev(NULL) {}
        ListNode(int value, int key_val, ListNode *n, ListNode *p) : val(value), key(key_val), next(n), prev(p) {}
    };

    int max_capacity;
    int cur_capacity;
    unordered_map<int, ListNode*> hash_table;
    ListNode *last_node;
    ListNode *head;

    LRUCache(int capacity) {
        max_capacity = capacity;
        cur_capacity = 0;
        head = NULL;
        last_node = NULL;
    }

    ListNode* allocate_node(int key, int value)
    {
        return (new ListNode(value, key));
    }

    void print_list()
    {
        ListNode *temp = head;

        while(temp) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout<<endl;
    }

    void add_node(ListNode *cur)
    {
        if(head == NULL) {
            head = cur;
            last_node = cur;
        } else {
            head->prev = cur;
            cur->next = head;
            head = cur;
        }
    }

    void delete_node(ListNode *to_delete)
    {
        if(head == to_delete) {
            head = head->next;

            if(head)
                head->prev = NULL;
                
            delete(to_delete);
        } else if(to_delete == last_node) {
            last_node = last_node->prev;
            last_node->next = NULL;
            delete(to_delete);
        } else {
            to_delete->prev->next = to_delete->next;
            to_delete->next->prev = to_delete->prev;
            delete(to_delete);
        }
    }

    int get(int key) 
    {
        auto iter = hash_table.find(key);

        if (iter != hash_table.end()) {

            int value = iter->second->val;
            
            delete_node(iter->second);
            hash_table.erase(iter);
            
            ListNode *cur = allocate_node(key, value);
            add_node(cur);
            hash_table.insert({key, cur});
            
            return (hash_table[key]->val);        
        } else {
            return -1;
        }
        
        return 0;
    }
    
    void put(int key, int value) 
    {
        auto iter = hash_table.find(key);

        if(iter != hash_table.end()) {
            delete_node(iter->second);
            hash_table.erase(iter);
            
            ListNode *cur = allocate_node(key, value);
            add_node(cur);
            hash_table.insert({key, cur});

        } else {
            ListNode *cur = allocate_node(key, value);
        
            if(max_capacity == cur_capacity) {
                auto iter = hash_table.find(last_node->key);
                hash_table.erase(iter);
                delete_node(last_node);
            
                add_node(cur);
                hash_table.insert({key, cur});

            } else if (cur_capacity < max_capacity ) {
                add_node(cur);
                hash_table.insert({key, cur});
                cur_capacity = cur_capacity + 1;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */