class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int mn = *min_element(begin(nums), end(nums));
        int mx = *max_element(begin(nums), end(nums));
        int avgGap = ceil((double)(mx-mn)/(double)(n-1)); //the average gap between the elements. The max difference is >= avgGap. This is because if there is only one gap bigger than this, thats the answer. If there is a gap smaller than avgGap then that implies that there is another pair where the diff is > avgGap.
        vector<int> bucketsMin(n-1, INT_MAX), bucketsMax(n-1, INT_MIN);

        for(auto i : nums) {
            if(i == mn || i == mx) continue;
            int idx = (i-mn)/avgGap;
            bucketsMin[idx] = min(bucketsMin[idx], i);
            bucketsMax[idx] = max(bucketsMax[idx], i);
        }

        int prev = mn; 
        int res = INT_MIN;
        for(int i = 0; i < n-1; ++i) {
            if(bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN) continue;
            res = max(res, bucketsMin[i]-prev);
            prev = bucketsMax[i];
        }

        return max(res, mx-prev);
    }
};