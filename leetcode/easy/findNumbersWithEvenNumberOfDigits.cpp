class Solution {
public:
    int findNumbers(vector<int>& nums) {
        auto check = [&](int i) {
            int cnt = 0;
            while(i) {
                i /= 10;
                ++cnt;
            }
            return !(cnt%2);
        };
        transform(begin(nums), end(nums), begin(nums), check);
        return accumulate(begin(nums), end(nums), 0);
    }
};