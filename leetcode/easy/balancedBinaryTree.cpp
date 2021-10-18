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
    int dfs(TreeNode* root) {
        //dfs will iterate all the way to the leftmost node, then traverse back up going to each right node (more preciseley said, the left nodes' parent's right node (left nodes neighbor)). each time it returns the length of the subtree + 1 for the parent node you are dfsing at. If ever the difference between a parent's left and right is greater than one, that tree isn't balanced. In this case we return -1.

        //dfs will return 0 when dfsing at the leaf nodes' nonexistent children
        if(root == NULL) return 0;
        //dfs left and right
        int left = dfs(root->left);
        int right = dfs(root->right);
        //if any of the subtrees are unbalnced, return -1
        if(left == -1) return -1;
        if(right == -1) return -1;
        //if the difference between two subtrees > 1 then return -1 since its unbalanced
        if(abs(left - right) > 1) return -1;
        //when this is at the leaf node, you will get max(0,0) + 1 (1 being the node you are dfsing at) This is the max hieght of the subtree + the parent node you are dfsing at
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
