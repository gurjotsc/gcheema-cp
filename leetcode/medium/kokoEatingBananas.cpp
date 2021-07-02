class Solution {
public:
    bool check (int k, vector<int>& piles, int h) {
        int hTotal = 0;
        int i = 0;
        for(int p : piles) {
          hTotal += = ceil(1.0 * p / k);
        }

        return hTotal <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 1e9;
        int low = 1;

        while(low < high) {
            int mid = low + (high - low) / 2;
            if(check(mid, piles, h)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
