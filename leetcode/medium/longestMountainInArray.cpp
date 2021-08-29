class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        if(arr.size() < 3) return ans;
        int i = 0;
        int base;
        int peak;
        while(i < arr.size()) {
            base = i;
            while(i + 1 < arr.size() && arr[i+1] > arr[i]) {
                ++i;
            }
            if(i == base) {
                ++i;
                continue;
            }
            peak = i;
            while(i + 1 < arr.size() && arr[i+1] < arr[i]) {
                ++i;
            }

            if(i == peak) {
                ++i;
                continue;
            }

            ans= max(ans, i - base + 1);
        }
        return ans;
    }
};
