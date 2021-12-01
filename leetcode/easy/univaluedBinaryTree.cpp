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
    bool isUnivalTree(TreeNode* root) {
        //Whole algorithm is just check if children exist, if they do check their value, and then return either false if its not the same as the root, or repeat the same problem for the left and right subtrees (assuming they exist)
        if(root->left != NULL && root->right != NULL) {
            if(root->left->val != root->val || root->right->val != root->val) return false;
            return isUnivalTree(root->left) && isUnivalTree(root->right);
        }
        else if(root->left != NULL) {
            if(root->left->val != root->val) return false;
            return isUnivalTree(root->left);
        }
        else if(root->right != NULL) {
            if(root->right->val != root->val) return false;
            return isUnivalTree(root->right);
        }
        return true;
    }
};
