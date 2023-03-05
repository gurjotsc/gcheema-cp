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
    map<int, long long> m;
    void dfs(TreeNode* root, int lvl) {
        if(root == NULL) return;
        m[lvl] += root->val;
        dfs(root->right, lvl+1);
        dfs(root->left, lvl+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        m.clear();
        dfs(root, 1);
        vector<long long> v;
        for(auto it : m) v.push_back(it.second);
        int n = v.size();
        sort(begin(v), end(v));
        return (n >= k) ? v[n-k] : -1;
    }
};