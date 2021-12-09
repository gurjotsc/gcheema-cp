class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        for(auto c : stones) {
            if(jewels.find(c) != string::npos) ++res;
        }
        return res;
    }
};
