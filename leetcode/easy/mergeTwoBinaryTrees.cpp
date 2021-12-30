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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(!r1) return r2; //in the case where r1 (or r1 of a subtree) is null, then your result is just the value of r2
        if(!r2) return r1; //same with this case
        r1->val += r2->val; //else its both the values summed up
        r1->left = mergeTrees(r1->left, r2->left); //the left child of r1 is going to be the function called on the two left children
        r1->right = mergeTrees(r1->right, r2->right); //same with the right
        return r1;
    }
};
