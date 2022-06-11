class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        for(auto& i : spells) {
            auto it = lower_bound(potions.begin(), potions.end(), ceil(success/(double)i));
            if(it == potions.end()) i = 0;
            else i = (m-(it - potions.begin()));
        }
        return spells;
    }
};