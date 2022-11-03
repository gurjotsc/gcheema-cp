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
    int p = -1, cnt = 0, mx = 0;
    vector<int> res;
    void dfs(TreeNode* r) {
        if(!r) return;
        dfs(r->left);
        cnt = (r->val == p) ? cnt+1 : 1;
        if(cnt > mx) {
            res.clear();
            res.push_back(r->val);
            mx = cnt;
        }
        else if(cnt == mx) res.push_back(r->val);
        p = r->val;
        dfs(r->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};