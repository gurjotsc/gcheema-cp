constexpr int INF = 1e9;
class Solution {
public:
    struct Sweep {
        int pos = 0;
        map<int, int> vs;
        vector<vector<int>> del;
        Sweep(int sz) : del(sz) {}
        inline void add(int v, int end) {
            ++vs[v];
            if(end < del.size()) del[end].push_back(v);
        }
        inline int get() {
            if(vs.empty()) return INF;
            else return begin(vs)->first;
        }
        inline void next() {
            for(auto v : del[pos]) {
                --vs[v];
                if(!vs[v]) vs.erase(v);
            }
            ++pos;
        }
    };
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<Sweep> vert(n, Sweep(m)); //a vertical sweep for each column
        for(int r = 0; r < m; ++r) {
            Sweep hori(n);
            for(int c = 0; c < n; ++c) {
                int hr = hori.get(), vt = vert[c].get();
                int v = 1+min(hr, vt);
                if(r == 0 && c == 0) v = 1;
                if(v < INF) {
                    if(r == m-1 && c == n-1) return v;
                    int val = grid[r][c];
                    hori.add(v, c+val);
                    vert[c].add(v, r+val);
                }
                hori.next();
                vert[c].next();
            }
        }
        return -1;
    }
};