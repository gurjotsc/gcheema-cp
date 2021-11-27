class Solution {
public:
    int findGCD(vector<int>& nums) {
        //Euclidian Algorithm
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());

        while(a) {
            int temp = a;
            a = b%a;
            b = temp;
        }

        return b;

        //c++ one liner
        // return __gcd((*max_element(nums.begin(), nums.end())), (*min_element(nums.begin(), nums.end())));
    }
};
