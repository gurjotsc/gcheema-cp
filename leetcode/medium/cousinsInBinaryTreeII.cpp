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
    unordered_map<int, int> m;
    void dfs(TreeNode* r, int lvl) {
        if(!r) return;
        m[lvl] += r->val;
        dfs(r->left, lvl+1);
        dfs(r->right, lvl+1);
    }
    void update(TreeNode* r, int lvl) {
        int tempL = (r->left) ? r->left->val : 0;
        int tempR = (r->right) ? r->right->val : 0;
        if(r->left) {
            r->left->val = m[lvl+1] - (tempL + tempR);
            update(r->left, lvl+1);
        }
        if(r->right) {
            r->right->val = m[lvl+1] - (tempL + tempR);
            update(r->right, lvl+1);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root, 0);
        root->val = 0;
        update(root, 0);
        return root;
    }
};