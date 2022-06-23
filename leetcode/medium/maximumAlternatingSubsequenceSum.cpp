class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long odd = 0, even = 0;
        for(auto& i : nums) {
            even = max(even, odd + i);
            //in the case where odd + i is taken
            //then the next line is basically (odd = (pdd+i)-i = odd) AKA just assume this one isn't taken since the max up until this number is stored in even
            odd = even - i;
        }
        return even;
    }
};