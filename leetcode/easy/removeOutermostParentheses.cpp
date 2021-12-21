class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        string res;
        int idxStart = 0;
        //keep track of when you reach a primitive string (when the parentheses are balanced)
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') ++balance;
            else --balance;
            if(!balance) {
                //update res with everything from idxStart to i (where the current balance is 0)
                for(int j = idxStart + 1; j < i; ++j) res.push_back(s[j]);
                idxStart = i + 1; //keeps track of when a new primitive string is started
            }
        }
        return res;
    }
};
