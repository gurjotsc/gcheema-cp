class Solution {
public:
    vector<int> factorize(int n) {
        unordered_set<int> res;
        int nn = n;
        for(int i = 2; i <= sqrt(n); ++i) if(!(n%i)) {
            res.insert(i);
            res.insert(n/i);
            nn /= i;
        }
        if(n > 1) res.insert(nn);
        return vector<int> (begin(res), end(res));
    }
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> fi;
        vector<int> line(10001);
        
        for(int i = 0; i < n; ++i) {
            for(auto f : factorize(nums[i])) {
                if(!fi.count(f)) fi[f]= i;
                ++line[fi[f]];
                --line[i];
            }
        }
            
        partial_sum(begin(line), end(line), begin(line));
        int res = find(begin(line), end(line), 0)-begin(line);
        return (res <= n-2) ? res : -1;        
    }
};