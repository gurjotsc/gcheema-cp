class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        int candy = n, i = 1;
        while(i < n) {
            while(i < n && r[i] == r[i-1]) {++i;}
            
            int peak = 0;
            while(i < n && r[i] > r[i-1]) {
                ++peak;
                candy += peak;
                ++i;
            }

            int valley = 0;
            while(i < n && r[i] < r[i-1]) {
                ++valley;
                candy += valley;
                ++i;
            }
            candy -= min(peak, valley); //you don't include the smaller final value of peak or min since the bigger one encapsulates it (say the valley value is reset to 1, so you subctract valley, if peak is smaller that means valley is bigger and peak was included in the some when it shouldn't have been (i.e the actual peak is 1,2,4 candies and then 4,3,2,1. It needed to be 4 for the values to be valid, but peak is calculate to be 1,2,3 in out algorithm, valley will count it as 4))
        }
        return candy;
    }
};