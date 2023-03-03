class Trie {
private:
    struct TrieNode {
        struct TrieNode* children[26];
        bool isWord;
    };
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto p = root;
        for(auto& c : word) {
            if(p->children[c-'a'] == NULL) {
                p->children[c-'a'] = new TrieNode();
            }
            p = p->children[c-'a'];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        auto p = root;
        for(auto& c : word) {
            if(p->children[c-'a'] == NULL) return false;
            p = p->children[c-'a'];
        }
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for(auto& c : prefix) {
            if(p->children[c-'a'] == NULL) return false;
            p = p->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */