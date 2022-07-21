class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        
        sort(begin(intervals), end(intervals),
            [] (vector<int>& a, vector<int>& b) {return a[1] < b[1];}); //sorted by endpoint
        
        for(int i = 1; i < n; ++i) {
            //don't change anything because the intervals[i-1][1] is a lesser end point than intervals[i][1] - this is simulating remooving intervals[i]
            if(intervals[i][0] < intervals[i-1][1]) {
                intervals[i] = intervals[i-1]; //saves space because we only compate i-1 with the next iteration. We could also just sort am "auto prev = intervals[i]" in the next else statement
                res++;
            }
        }
        return res;
    }
};