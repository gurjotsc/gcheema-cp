class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0, r = 0; //left open '(' and right open ')' respectivley
        //keep track of the parentheses. if you see ")" and your r is not 0 then decrease your r because there is a'(' that needs to be closed. else if you see ')' and the r is 0 then you can increment res because you are missing a '(' before it. If you see a '(' (last case) then increment your r as you will pop it because the first if is gonna get triggered when you encounter a '('
        //return l + r since l will keep track of how many open '(' there are and r keeps track of how many ')' are open
        for(auto c : s) {
            if(c == ')' && r) --r;
            else if(c == ')') ++l;
            else {
                ++r;
            }
        }
        return l + r;
    }
};
