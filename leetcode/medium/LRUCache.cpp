class DLNode {
    public:
        int key, value;
        DLNode* next, *prev;
        DLNode(int k, int v) {
            key = k; value = v;
            next = NULL; prev = NULL;
        }
        DLNode() {next = NULL; prev = NULL;}
};
class LRUCache {
public:
    unordered_map<int, DLNode*> m;
    DLNode* head = new DLNode();
    DLNode* tail = new DLNode();
    int n, cnt = 0;
    //the node that goes in the map is the same as the one in the list (the exact same as in the same element, not a copy) This is a map of keys to nodes in the list so that you can access the internal nodes of the list in O(1)
    
    //////////////////////////////////////////////////////////////////////////////////////////
    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) { 
        if(m.count(key)) {
            moveToHead(m[key]);
            return m[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            m[key]->value = value;
            moveToHead(m[key]);
        }
        else {
            auto node = new DLNode(key, value);
            m[key] = node;
            add(node);
            if(cnt >= n) removeBack();
            else cnt++;
        }
        
    }
    
    
    void moveToHead(DLNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        add(node);
    }
    void add(DLNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void removeBack() {
        DLNode* del = tail->prev;
        tail->prev = del->prev;
        tail->prev->next = tail;
        m.erase(del->key);
        delete del;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */