class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int n = b1.size();
        long long res = 0;
        unordered_map<int, int> m;
        vector<int> swaps;

        for(auto i : b1) ++m[i];
        for(auto i : b2) --m[i];
        for(auto i : m) {
            if(i.second%2) return -1;
            for(int j = 0; j < abs(i.second)/2; ++j) swaps.push_back(i.first);
        }
        sort(begin(swaps), end(swaps));
        int mn = min(
            *min_element(begin(b1), end(b1)),
            *min_element(begin(b2), end(b2))
        );

        for(int i = 0; i < swaps.size()/2; ++i)
            res += min(2*mn, swaps[i]);
        
        return res;
    }
};