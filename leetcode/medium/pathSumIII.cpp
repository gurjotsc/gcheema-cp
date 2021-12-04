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
    int prefix(TreeNode*& root, int targetSum, int currSum, unordered_map<int, int> m) {
        currSum += root->val; //increment the prefixSum of the current node

        //res is going to store the current nodes answer (i.e. how many paths from the current node give you the target sum)
        int res = 0;
        //update res by how many ways you can achieve the targetSum using values in the past you have seen (m[currSum-targetSum])
        if(m.find(currSum - targetSum) != m.end()) res += m[currSum - targetSum];

        //push it to the map so you can use it for the next recursions comparisons
        if(m.find(currSum) == m.end()) m[currSum] = 1;
        else ++m[currSum];
        //Update res by the answer of the left and right subtree
        if(root->left) res += prefix(root->left, targetSum, currSum, m);
        if(root->right) res += prefix(root->right, targetSum, currSum, m);
        return res; //the res we return is technically only the res of the node we called it on
        //BUT the first call is actually going to += it with its children's subtrees (hence the two calls above) that will do the same thing, thus giving us the total answer
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        unordered_map<int, int> m;
        m[0] = 1; //Prefix buffer
        int currSum; //stores the current nodes sum
        return prefix(root, targetSum, currSum = 0, m);
    }
};
