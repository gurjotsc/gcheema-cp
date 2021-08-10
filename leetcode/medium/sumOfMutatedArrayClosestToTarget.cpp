class Solution {
public:
    void check (vector<int>& arr, int target, int val, int& closest) {
        for(int i = 0; i < arr.size(); i++) {
          if(arr[i] >= val) {
              arr[i] = val;
          }
          else {
              arr[i] = 0;
          }
        }
        if(abs(target - arr.sum()) < closest)
            closest = abs(target - arr.sum());

         return;

    }
    int findBestValue(vector<int>& arr, int target) {
        int hi = 10e5;
        int lo = 0;
        int closest;
        while (lo < hi) {
           int mid = lo + (hi - lo) / 2;
           if(closest > check(arr, target, mid, closest)){
             hi = mid;
          }
          else {
             lo = mid + 1;
          }
        }
        return lo;
    }
};
