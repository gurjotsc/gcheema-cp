class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int res = 0;
        vector<int> rows(m);
        vector<int> cols(n);
        for(auto i : indices) {
            int r = i[0];
            int c = i[1];
            ++rows[r];
            rows[r] %= 2;
            ++cols[c];
            cols[c] %= 2;
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(cols[j] != rows[i]) ++res;
            }
        }

        return res;
    }
};

//         c1   c2.  c3
//         e.   o.   e
// r1 o
// r2 e
//      c1   c2.  c3
//      e.   e   e
// r1 o
// r2 o




// ee = e
// oo = e
// eo = o
// oe = o
