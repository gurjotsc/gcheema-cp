class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo = 0, hi = 1e14;
        while(lo < hi) {
          long long mid = lo + ((hi-lo)/2), n = 0;
          for(auto& r : ranks) n += (int)(sqrt(mid/r));
          if(n < cars) lo = mid+1;
          else hi = mid;
        }
        return lo;
    }
};