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
    int res;
    void dfs(TreeNode* root, int parityTracker) {
        if(!root) return;
        if(!root->left && !root->right) {
            int cnt = __builtin_popcount(parityTracker ^ (1 << (root->val-1)));
            res += (cnt <= 1);
            return;
        }
        dfs(root->left, parityTracker ^ (1 << (root->val-1)));
        dfs(root->right, parityTracker ^ (1 << (root->val-1)));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        res = 0;
        dfs(root, 0);
        return res;
    }
};