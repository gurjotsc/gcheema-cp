class Solution {
public:
    int steps(string a, string b) {
        int res = 0;
        int i = 0, j = 0, n = a.size();
        while(i < n) {
            j = i;
            while(b[j] != a[i]) ++j;
            while(i < j) {
                swap(b[j], b[j-1]);
                res += 1;
                --j;
            }
            ++i;
        }
        return res;
    }
    int getMinSwaps(string original, int k) {
        string num = original;
        while(k--) next_permutation(begin(num), end(num));
        return steps(original, num);
    }
};