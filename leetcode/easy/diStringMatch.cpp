class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> res(n+1);
        int lo = 0, hi = n; //if the first charater is an I it should be the lowest integer in res but if the first is D it should be the highest integer in res (which can't be higher than n)
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'I') {
                res[i] = lo++; //this will ensure if another I is encountered, down the line it will be assigned a higher integer than the previous I
            }
            else {
                res[i] = hi--; //this will ensure if another D is encountered, down the line it will be assigned a lower integer than the previous D
            }
        }
        //you know that lo will be higher than all the I's but lower than the hi's (also hi will never be lower than lo because in the case of all D's, hi will go to 1 leaving lo at 0)
        res[n] = lo;
        return res;
    }
};
