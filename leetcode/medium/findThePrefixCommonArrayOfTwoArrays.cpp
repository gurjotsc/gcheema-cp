class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        set<int> a, b;
        int curr = 0;
        for(int i = 0; i < n; ++i) {
            if(A[i] == B[i]) {
                ++curr;
                goto end;
            }
            
            if(a.count(B[i]) && b.count(A[i])) curr += 2;
            else if(a.count(B[i])) ++curr;
            else if(b.count(A[i])) ++curr;

            end: {
                res[i] = curr;
                a.insert(A[i]);
                b.insert(B[i]);
            }
        }
        return res;
    }
};