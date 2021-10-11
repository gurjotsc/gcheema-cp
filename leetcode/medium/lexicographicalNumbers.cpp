class Solution {
public:
    /*
                        1                    2           3
              /                  \        /    \      /     \
             10..................19     20.....29   30.....39
            /  \       /    \
         100...109    180...189
    */
    void dfs(int cur, int n, vector<int>& res) {
        if(cur > n) return; //cur is too big
        res.push_back(cur); //if its valid then pushback
        for(int i = 0; i <= 9; ++i) {
            dfs(10*cur+i, n, res);
            //here we iteraate through every digit possible (0-9) and do a preorder traversal                 which is just root->left->right (again, see top trees. Note pre order does all                   children before moving down to next level)
        }
    }
    vector<int> lexicalOrder(int n) {
        //perform a preorder traversal on each digit                                                     //(you can think of each digit as a binary                                                       //tree) see top
        vector<int> res;
        for(int i = 1; i <= 9; ++i) dfs(i, n, res);
        return res;
    }
};
