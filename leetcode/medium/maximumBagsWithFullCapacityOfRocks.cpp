class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for(int i = 0; i < n; ++i) capacity[i] -= rocks[i];
        sort(capacity.begin(), capacity.end());
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(additionalRocks <= 0) break;
            if(capacity[i] - additionalRocks > 0) break;
            additionalRocks -= capacity[i];
            ++res;
        }
        return res;
    }
};