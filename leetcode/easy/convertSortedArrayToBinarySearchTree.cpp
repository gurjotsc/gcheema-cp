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
    TreeNode* recurse(vector<int>& nums, int l, int r) {
        if (l == r) {
            auto temp = new TreeNode(nums[l]);
            return temp;
        }
        else if(l > r) return nullptr;
        
        int mid = (l+r)/2;
        auto p = new TreeNode(nums[mid]);
        p->left = recurse(nums, l, mid-1);
        p->right = recurse(nums, mid+1, r);
        return p;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurse(nums, 0, nums.size()-1);
    }
};