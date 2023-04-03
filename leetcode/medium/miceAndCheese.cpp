class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        int n = r1.size();
        vector<int> diff(n);
        int res = 0;
        for(int i = 0; i < n; ++i) {
            diff[i] = r1[i]-r2[i];
            res += r2[i];
        }

        sort(rbegin(diff), rend(diff));
        for(int i = 0; i < k; ++i) res += diff[i];
        
        return res;
    }
};