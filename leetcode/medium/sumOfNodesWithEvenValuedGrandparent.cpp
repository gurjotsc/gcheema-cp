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
    int sum;
    void recurse(TreeNode* root, int p, int gp) {
        if(!(gp%2)) sum += root->val;
        if(root->left) recurse(root->left, root->val, p);
        if(root->right) recurse(root->right, root->val, p);
    }
    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;
        recurse(root, -1, -1);
        return sum;
    }
};