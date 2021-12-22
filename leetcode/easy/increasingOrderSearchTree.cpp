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
    TreeNode* increasingBST(TreeNode* root, TreeNode* parent = NULL) {
        if(!root) return parent; //just return the leaf (parent) node at the end of the tree
        //your result will be the inorder traversak (left, root, right) since its a BST
        //res is going to be what you return. It will find the leftmost value we haven't already recursed on, return the above case, and start the inorder traversal
        //in the case of the leaf node where this returns the parent, remember, that this is actually a pointer to the parent. so when we change root below, we are still updating res.
        auto res = increasingBST(root->left, root);
        root->left = NULL; //make the left null since the left is stored in res now
        //compute the inorder of the right half of the tree
        root->right = increasingBST(root->right, parent);
        return res;
    }
};
