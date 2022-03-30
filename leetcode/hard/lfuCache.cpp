using ll = long long;

class LFUCache {
public:
    int n, cnt = 0;
    unordered_map<int, pair<int, int>> m; //store keys to {value, freq}
    unordered_map<int, list<int>::iterator> nodes; //stores key to an iterator to that key's node
    unordered_map<int, list<int>> freq; //stores freq to a doubly-linked list that stores all keys for that freq
    int minF = INT_MAX; //minFrequency
    
    
    LFUCache(int capacity) { n = capacity; }
    
    int get(int key) {
        if(m.count(key)) {
            update(key);
            return m[key].first;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(!n) return;
        if(!m.count(key)) {
            if(cnt < n) cnt++;
            else {
                int removeKey = freq[minF].front(); freq[minF].pop_front();
                m.erase(removeKey); nodes.erase(removeKey);
            }
            
            m[key] = {value, 1};
            freq[1].push_back(key);
            nodes[key] = --freq[1].end();
            minF = min(minF, m[key].second);
        }
        else {
            m[key].first = value;
            update(key);
        }
    }
    void update(int key) {
        int currF = m[key].second;
        freq[currF].erase(nodes[key]);
        freq[++m[key].second].push_back(key);
        nodes[key] = --freq[currF+1].end();
        if(!freq[minF].size()) ++minF; //Means m[key] was the previous least Freq Used
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */