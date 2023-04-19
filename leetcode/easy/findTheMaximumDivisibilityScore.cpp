class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n = divisors.size();
        int mx = INT_MIN;
        int res;
        map<int, int> m;
        for(auto d : divisors) if(!m.count(d)){
            int cnt = 0;
            for(auto j : nums) cnt += (!(j%d));
            mx = max(mx, cnt);
            m[d] = cnt;
        }
        for(auto it : m) if(it.second == mx)
            return it.first;
        return -1;
    }
};