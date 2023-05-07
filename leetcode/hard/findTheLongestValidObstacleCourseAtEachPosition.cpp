class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        int n = ob.size();
        vector<int> res(n), v;
        for(int i = 0; i < n; ++i) {
            int idx = upper_bound(begin(v), end(v), ob[i]) - begin(v);
            if(idx == v.size()) v.push_back(ob[i]);
            else v[idx] = ob[i];
            res[i] = idx+1; //length of subsequence
        }
        return res;
    }
};