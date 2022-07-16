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
    int mn, mx;
    int res;
    void dfs(TreeNode* r, int mn, int mx) {
        mn = min(r->val, mn); mx = max(r->val, mx);
        res = max(res, abs(mx-mn));
        if(r->left) dfs(r->left, mn, mx);
        if(r->right) dfs(r->right, mn, mx);
    }
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        dfs(root, root->val, root->val);
        return res;
    }
};