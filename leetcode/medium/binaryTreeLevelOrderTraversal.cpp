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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        //perform bfs
        while(!q.empty()) {
            int n = q.size();
            vector<int> curr(n);
            //for each iteration, we want to iterate through all the nodes in the queue and add their children to a our current level order traversal vector (curr)
            //we also want to push any children into the queue for the next iteration of the while loop
            for(int i = 0; i < n; ++i) {
                auto temp = q.front(); q.pop();
                curr[i] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(curr);
        }
        return res;
    }
};
