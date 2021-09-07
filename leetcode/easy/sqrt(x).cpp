class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        if(x == 1) return 1;
        int lo = 0;
        int hi = x;
        int ans = 0;
        // condition needs to be equal to because when you update lo, its possible that on the next iteration, hi decrease to mid - 1 which could be equal to lo, hence the < OR = condition
        while(lo <= hi) {
            //set mid
            int mid = lo + ((hi - lo) / 2);
            //x/mid should = mid for it be the sqrt. If its less than, then we know that the answer it higher than mid, hence we update lo
            if(mid <= x/mid) {
                lo = mid + 1;
                ans = mid;
            }
            //else increase hi (since the ans needs to be lower)
            else hi = mid - 1;
        }
        return ans;
    }
};
