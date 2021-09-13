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
    int min;
    long ans = LONG_MAX; //If you use INT_MAX then if INT_MAX is the answer it won't update ans
    void dfs(TreeNode* root) {
        if(root != NULL) { //If the root is NULL it just returns

            if(min < root->val && root->val < ans) ans = root->val; //If the value that you are checking is more than the absolute minimum, and it is lower than ans, then you know this is the best condidate to be the second smallest number so far.

            else {//If the value you checked does not meet the upper conditions, then you waant to look further
                dfs(root->left);
                dfs(root->right);
            }
        }

    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left == NULL) return -1; //Return -1 for invalid trees
        min = root->val; //The first node stores all the lowest node since it always takes the value of the minimum of its children.
        dfs(root); //DFS to find second lowert
        return ans < LONG_MAX ? (int)ans : -1;
    }
};
