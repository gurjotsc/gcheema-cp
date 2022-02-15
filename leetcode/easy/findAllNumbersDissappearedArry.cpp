class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+1);
        vector<int> res;
        for(int i = 1; i <= n; ++i) temp[i] = 1;
        for(auto i : nums) temp[i] = 0;
        for(int i = 1; i <= n; ++i) {
            if(temp[i] == 1) res.push_back(i);
        }
        return res;
        
    }
};