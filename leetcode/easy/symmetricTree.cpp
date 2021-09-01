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
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    bool checkIsSymmetric(TreeNode* rootL, TreeNode* rootR) {
        if(rootL == NULL && rootR == NULL) return true;
        else if(rootL == NULL || rootR == NULL) return false;
        else if(rootL->val != rootR->val) return  false;
        else return checkIsSymmetric(rootL->left, rootR->right) && checkIsSymmetric(rootL->right, rootR->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* p = root->left;
        TreeNode* q = root->right;
        return checkIsSymmetric(p, q);

    }
};
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE
