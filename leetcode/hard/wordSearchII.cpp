class TrieNode {
    public:
        string word;
        vector<TrieNode*> children;
        TrieNode() {
            children = vector<TrieNode*>(26, NULL);
        }
};

class Trie {
    public:
        void addWord(const string& w) {
            auto p = root;
            for(auto c : w) {
                if(p->children[c-'a'] == NULL) p->children[c-'a'] = new TrieNode();
                p = p->children[c-'a']; 
            }
            p->word = w;
        }

        Trie(vector<string> word) {
            root = new TrieNode();
            for(auto w : word) addWord(w);
        }

        TrieNode* root;
};

class Solution {
public:
    unordered_set<string> res;
    int m, n;
    vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    void dfs(vector<vector<char>>& b, TrieNode* r, int i, int j, string curr = "") {
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(b[i][j] == '0') return;

        char c = b[i][j];
        if(r->children[c-'a'] == NULL) return;
        
        curr += c;
        if(r->children[c-'a']->word != "") res.insert(curr);
        b[i][j] = '0';

        for(const auto& [x, y] : dirs) dfs(b, r->children[c-'a'], i+x, j+y, curr);

        b[i][j] = c;
    } 
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        m = b.size(), n = b[0].size();
        Trie* trie = new Trie(words);
        TrieNode* r = trie->root;
        res.clear();

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) 
                dfs(b, r, i, j);

        return vector<string>(begin(res), end(res));
        


        return {""};
    }
};