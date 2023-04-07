using ll = long long;
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        ll n = arr.size(), res = 0;
        for(int i = 0; i < k; ++i) {
            vector<ll> cycles;
            for(int j = i; arr[j] != -1; j = (j+k)%n) {
                cycles.push_back(arr[j]);
                arr[j] = -1;
            }
                
            nth_element(begin(cycles), begin(cycles)+(cycles.size()/2), end(cycles));
            for(auto x : cycles) 
                res += abs(x-cycles[cycles.size()/2]);
        }
        return res;
    }
};