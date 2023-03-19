class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> modsFreq;
        for(auto& i : nums) {
            if(i >= 0) ++modsFreq[i%value];
            else ++modsFreq[((i%value)+value)%value];
        }
        
        for(int i = 0; i <= 1e5; ++i) {
            if(!modsFreq[i%value]) return i;
            --modsFreq[i%value];
        }
        
        return 0;
    }
};