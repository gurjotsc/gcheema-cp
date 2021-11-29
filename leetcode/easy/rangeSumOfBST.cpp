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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(root->val > high) return rangeSumBST(root->left, low, high);
        //if the current value if greater than high, then you want to probe the left branch of the current root, since all those values will be less than the current root
        if(root->val < low) return rangeSumBST(root->right, low, high);
        //if the current value if lower than low, then you want to probe the right branch of the current root, since all those values will be more than the current root
        return root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
        //else the root is in between the range so you still want to probe both the left and right branches while also adding root->val
    }
};
