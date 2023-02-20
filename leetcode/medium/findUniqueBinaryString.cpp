class Solution {
public:
    int n;
    string res;
    void check(const unordered_set<string>& s, string r, int i) {
        if(res != "") return;
        if(i == n) {
            if(s.find(r) == end(s)) res = r;
            return;
        }
        check(s, r, i+1);
        r[i] = '1'; check(s, r, i+1);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        //I feel liek you could prob precompute every possibility
        //Store in map<size, vector<string>>
        //Check over the vector that corresponse to nums.size()
        unordered_set<string> s(begin(nums), end(nums));
        n = nums.size();
        res = "";
        string r(n, '0');
        check(s, r, 0);
        return res;
    }
};