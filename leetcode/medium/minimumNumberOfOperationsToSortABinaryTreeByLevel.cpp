/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> m;
    int depth;
    void dfs(TreeNode* r, int lvl) {
        if(!r) return;
        depth = max(depth, lvl);
        m[lvl].push_back(r->val);
        dfs(r->left, lvl+1);
        dfs(r->right, lvl+1);
    }
    int minimumOperations(TreeNode* root) {
        int res = 0;
        m.clear();
        depth = 0;
        dfs(root, 0);
        for(int i = 1; i <= depth; ++i) {
            vector<int> v = m[i];
            sort(begin(v), end(v));
            unordered_map<int, int> idx;
            for(int j = 0; j < v.size(); ++j) 
                idx[v[j]] = j;
            
            int swaps = 0;
            for(int j = 0; j < v.size(); ++j) {
                int val = m[i][j];
                int correctIdx = idx[val];
                if(j == correctIdx) continue;
                int currIdx = j;
                while(currIdx != correctIdx) {
                    swap(m[i][currIdx], m[i][correctIdx]);
                    val = m[i][currIdx];
                    correctIdx = idx[val];
                    ++swaps;
                }
            }
            res += swaps;
        }
        return res;
    }
};