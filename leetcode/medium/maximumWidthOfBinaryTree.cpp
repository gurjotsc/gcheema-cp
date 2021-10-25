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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        //bfs q
        //stores the node you are bfsing as well as the index of the node
        //Imagine a tree represented as an array - we are storing that index
            //Each level would be stored side by side
            //Each child of a parent would be stored at index 2*i (left) and 2*i+1 (right)
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 1}); //start at index level 1
        unsigned int res = 0; //unsigned is used to prevent overflow
        //begin bfs
        //here you want to run until q is empty
        //Each iteration, you will pop all the parents in a row and be left with their children           in the queue. You then perform the same process to the children.
        //By storing the distance of each child in the row you can calculate the width of a               given level
        while(!q.empty()) {
            int left = q.front().second;
            unsigned int right = left; // right and left are going to start in the same spot
            //we can't use q.size() in the for loop condition because it is going to get                     updated with each iterationg as we push children into the q
            int n = q.size();
            //iteratre through the parents pushed in the queue
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front().first; // current node you are bfsing on
                right = q.front().second; //going to hold index of the parent
                q.pop();
                // if the parent has a child push it and store the appropriate index
                if(node->left != NULL) q.push({node->left, right*2});
                if(node->right != NULL) q.push({node->right, (right * 2) + 1});

                //note the indexes stored for each node DO NOT correspond to location in the q
                //the q is popping with every itearation so the q only ever holds one level at                  a time
                //the second number in q stores what the position in an array WOULD be
            }
            //we always end the former loop with the rightmost node so we can see the width by              subtracting right and left and adding 1 (for indexing issues (aka the width is the              number of nodes that could fit in between the rightmost and leftmost nodes))
            //res stores the maximum we've seen
            //we cast to unsigned in to make sure it is the same type as res since max can only               take arguments of the same type
            res = max(res, ((unsigned int)right) - ((unsigned int)left) + 1);
        }
    return res;
    }
};
