class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        int n = target.size();
        //wall of bricks
        //once we perform an operation, you can't perform it after anything that was lower than it(i.e 3, 1, 2 - res updates by three but still needs to update by 1 for the last two since it isn't part of the first subarray. It should only update by target[i] - target[i-1] because the previous subarray has technically updated the current value by at least target[i-1])
        for(int i = 1; i < n; ++i) {
            if(target[i-1] <= res && target[i] > target[i-1]) {
                res += (target[i] - target[i-1]);
            }
        }
        return res;
    }


};
