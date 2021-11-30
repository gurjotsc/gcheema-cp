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
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int parentVal = INT_MAX) {
        //if you finished checking through the array OR current idx reaches a val > parentVal
        //preorder[i] >= parentVal indeicate the right branch of a parent is beginning
        if(i >= preorder.size() || preorder[i] >= parentVal) return nullptr;
        //use new to make it a pointer to a TreeNode
        auto n = new TreeNode(preorder[i++]);
        //the left subtree is going to pass in n->val since if the next value in preorder is     greater than n->val (which is the parent of the left node) we need to stop and return a nullptr (indicated in line 1 of the function) since we are now looking at the right subtree of the parent
        n->left = bstFromPreorder(preorder, n->val);
        //pass in parentVal since this should always pass INT_MAX to get to the right most leaf node (the largest value). the line above this will take care of left value in the right subtree of the entire tree
        n->right = bstFromPreorder(preorder, parentVal);
        return n;
    }
};
