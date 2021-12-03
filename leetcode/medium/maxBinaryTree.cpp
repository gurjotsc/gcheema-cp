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
    TreeNode* arrayToTree(vector<int>& nums, int l, int r) {
        if(l >= r) return NULL; //Base Case

        int m = INT_MIN;
        int maxIndex = l;
        //Find the maximum value
        for(int i = l; i < r; ++i) {
            if(m != max(m, nums[i])) {
                m = max(m, nums[i]);
                maxIndex = i;
            }
        }

        TreeNode* subRoot = new TreeNode(m); //creates a root with the maximum value
        subRoot->left = arrayToTree(nums, l, maxIndex); //the left subtree is the left prefix
        subRoot->right = arrayToTree(nums, maxIndex + 1, r); //the right subtree is the right prefix
        return subRoot;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return arrayToTree(nums, 0, nums.size());
    }
};
