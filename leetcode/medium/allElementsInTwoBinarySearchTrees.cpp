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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root1 && root2){
            q.push(root1);
            q.push(root2);
        }
        else if(root1) q.push(root1);
        else if(root2) q.push(root2);
        //simple bfs then sort at the end
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            res.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
