class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for(auto& i : strs) {
            bool hasAlpha = false;
            int n = i.size();
            for(auto& j : i) {
                if(isalpha(j)) {
                    hasAlpha = true;
                    break;
                }
            }
            if(hasAlpha) res = max(res, n);
            else res = max(res, atoi(i.c_str()));
        }
        return res;
    }
};