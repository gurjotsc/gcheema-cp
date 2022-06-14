class Solution {
public:
    int res, n;
    void recurse(int x, vector<int>& cookies, vector<int> kids, int k) {
        if(x == n) {
            res = min(res, *max_element(kids.begin(), kids.end()));
            return;
        }
        if(*max_element(kids.begin(), kids.end()) >= res) return;
        for(int i = 0; i < k; ++i) {
            auto temp = kids;
            temp[i] += cookies[x];
            recurse(x+1, cookies, temp, k);
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        res = INT_MAX;
        vector<int> kids(k, 0);
        recurse(0, cookies, kids, k);
        return res;
    }
};