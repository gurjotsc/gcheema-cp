class Solution {
public:
    bool check(vector<int>& weights, int days, int weightCapacity) {
        int store = 0;
        int daysCount = 1;
        for (int i = 0; i < weights.size(); ++i) {
            int w = weights[i];
            if (w > weightCapacity) return false;
            if (w + store <= weightCapacity) store += w;
            else {
                store = w;
                daysCount++;
            }
            if (daysCount > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 1;
        int hi = 5e6;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(weights, days, mid))
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
