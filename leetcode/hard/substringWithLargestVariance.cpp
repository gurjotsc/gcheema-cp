class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        unordered_set<char> inString(s.begin(), s.end());
        
        int res = 0;
        for(int c = 'a'; c <= 'z'; ++c) 
            for(int x = 'a'; x <= 'z'; ++x) {
                if(c == x) continue;
                if(!inString.count(c) || !inString.count(x)) continue;
                int cCnt = 0, xCnt = 0;
                bool includePrevX = false;
                for(auto i : s) {
                    cCnt += (i == c);
                    xCnt += (i == x);
                    if(xCnt > 0) res = max(res, cCnt-xCnt);
                    else if(!xCnt && includePrevX) res = max(res, cCnt-1); //-1 because of 
                                                                          //previous q
                    if(xCnt > cCnt) { //restart interval because this interval will be negative
                        //ex: cxxcccccccc
                        //because we need at least 1 x, we want to include the previous x so we have xcccccccc in res
                        cCnt = xCnt = 0;
                        includePrevX = true;
                    }
                    
                }
            } 
                
        return res;
    }
};