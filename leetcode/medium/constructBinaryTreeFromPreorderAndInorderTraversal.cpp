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
    int preorderIdx = 0;
    unordered_map<int, int> inorderIndicies; //stores the value and their indicies
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if(left > right) return NULL; //return null when theres no more values
        TreeNode* subRoot = new TreeNode(preorder[preorderIdx++]); //stores the root of the subtree. The next value in preorder will be a child of the previous unless you get to a value which represent a previous parents root (we use inorderIndicies to find this index)
        subRoot->left = arrayToTree(preorder, left, inorderIndicies[subRoot->val] - 1); //the left subtree if going to equal everything from your left bound up to the rootvalue you have (not including it) We use the inorder idx because it stores the
        subRoot->right = arrayToTree(preorder, inorderIndicies[subRoot->val] + 1, right); //constructs the right subtree
        return subRoot; //will return each subTree
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) inorderIndicies[inorder[i]] = i; //store indicies in the hashmap
        return arrayToTree(preorder, 0, preorder.size()-1); //perform the construction on the entire array
    }
};
