class Solution {
public:
    int n, res;
    void update(int i, int x, array<int, 1001>& a) {
        if(i > 0 && i <= 1000) a[i] += x;
    }
    void dfs(const vector<int>& nums, int k, int i, array<int, 1001>& a) {
        if(i == n) return;
        if(a[nums[i]]) {
            dfs(nums, k, i+1, a);
            return;
        }
        int x = nums[i];
        ++res;

        update(k+x, 1, a);
        update(x-k, 1, a);
        dfs(nums, k, i+1, a);

        update(k+x, -1, a);
        update(x-k, -1, a);
        dfs(nums, k, i+1, a);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size(), res = 0;
        array<int, 1001> a{};
        dfs(nums, k, 0, a);
        return res;
    }
};