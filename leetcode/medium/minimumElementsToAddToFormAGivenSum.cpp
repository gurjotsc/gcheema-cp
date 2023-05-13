using ll = long long;
class Solution {
public:
    int minElements(vector<int>& nums, ll limit, ll goal) {
        ll sm = accumulate(begin(nums), end(nums), 0ll);
        ll diff = abs(goal - sm);
        return(!(diff%limit)) ? (diff/limit) : (diff/limit)+1;
    }
};