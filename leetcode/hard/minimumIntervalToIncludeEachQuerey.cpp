class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
             {return (a[1]-a[0]) < (b[1]-b[0]);}
            );
        multiset<int> q(queries.begin(), queries.end());
        unordered_map<int, int> m;
        for(auto& i : intervals) {
            int l = i[0], r = i[1];
            int sz = r-l+1;
            auto it = q.lower_bound(l);
            while(it != q.end() && *it <= r) {
                m[*it] = sz;
                it = q.erase(it); //.erase() returns the next iterator
            }
        }
        vector<int> res(n, -1);
        for(int i = 0; i < n; ++i)
            if(m.count(queries[i])) res[i] = m[queries[i]];
        return res;
    }
};