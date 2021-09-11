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
    int ans = 0;
    void dfs(TreeNode* root, int tempDepth) {
        //If the current node is a leaf node then just set ans to tempDepth if its bigger
        if(root->left == NULL && root->right == NULL) ans = max(ans, tempDepth);
        //if not then you wanna dfs at each child node that exists and increase tempDepth by 1 for each row in
        //the binary tree
        else {
            if (root->left) dfs(root->left, tempDepth+1);
            if (root->right) dfs(root->right, tempDepth+1);
            //Note you can't use pre/postfix increment operators in the function call of tempDepth because you
            //don't want to increase tempDepth for both the right and the left each, but rather just once per
            //row in the tree
        }
    }
    int maxDepth(TreeNode* root) {
        //If its NULL return 0;
        if(root == NULL) return 0;
        //The reason we start with one is because the root node counts as a 1 depth binary tree
        dfs(root, 1);
        return ans;
    }
};
