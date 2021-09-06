struct Node { // Creates a node that stores key and val with a pointer to the next
public:
    int key, val;
    Node* next;
    Node(int k, int v, Node* n) {
        key = k;
        val = v;
        next = n;
    }
};
class MyHashMap {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size];
    int hash(int key) {
        return (int)((long)key * mult % size); //Hashes the inputed key
    }
    void put(int key, int val) {
        remove(key); //Removes key in case of duplicate
        int h = hash(key);
        Node* node = new Node(key, val, data[h]);  //Creates a new node for data h
        data[h] = node;
    }
    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        for (; node != NULL; node = node->next)
            if (node->key == key) return node->val;
        return -1;
    }
    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL) return;
        if (node->key == key) data[h] = node->next;
        else for (; node->next != NULL; node = node->next)
            if (node->next->key == key) {
                node->next = node->next->next;
                return;
            }
    }
};
