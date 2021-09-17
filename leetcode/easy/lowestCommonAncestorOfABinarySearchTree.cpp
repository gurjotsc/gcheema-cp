/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //We know that for a BST all values to the right of a node are greater than it and all of the ones to the left are less than the value.

        //From this we know that if p and q are greater than the node, the answer will be on the right of the current node (the answer could very well be one of p or q themselves, but even these would be on the right of the root if they are bigger than it). If the condition is met we LCA on the right node.
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

        //Similarly, if they are both less than root, then they will be on the left side.
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);

        //If one or the other doesn't meet the conditions above that either means that the root is either p or q, or, the current root is the LCA (if we were to continue left or right, we wouldn't parent the opposite node anymore)
        return root;
    }
};
