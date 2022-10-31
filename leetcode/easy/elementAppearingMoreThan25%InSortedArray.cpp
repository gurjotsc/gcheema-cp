class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, double> freq;
        double n = arr.size();
        for(auto& i : arr) {
            freq[i]++;
            if(freq[i]/n > 0.25) return i;
        }
        return -1;
    }
};