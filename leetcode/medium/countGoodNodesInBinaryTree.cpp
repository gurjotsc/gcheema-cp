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
    int goodNodes(TreeNode* root) {
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        //you could do this with better space using dfs since you wouldn't need a queue
        //perform bfs
        while(!q.empty()) {
            auto [curr, m] = q.front(); q.pop();
            //if the new node is >= the max before it then it is valid, Push it to the q with the new max
            if(curr->right){
                if(curr->right->val >= m) ++res;
                q.push({curr->right, max(m, curr->right->val)});
            }
            //if the new node is >= the max before it then it is valid, Push it to the q with the new max
            if(curr->left){
                if(curr->left->val >= m) ++res;
                q.push({curr->left, max(m, curr->left->val)});
            }

        }
        return res;
    }
};
