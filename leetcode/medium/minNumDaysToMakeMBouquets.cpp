class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int day) {
        int consecutive = 0;
        int mRemaining = m;
        for(int b : bloomDay) {
            if(b <= day) {
                consecutive++;
            }
            else {
                consecutive = 0;
            }

            if(consecutive == k) {
                consecutive = 0;
                mRemaining--;
            }
        }

        return mRemaining <= 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < m * k) {
            return -1;
        }

        int high = 1e9;
        int low = 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if(check(bloomDay, m, k, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;

    }
};
