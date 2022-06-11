class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        vector<int> p(1002, 0);
        for(int i = 0; i < n; ++i) {
            p[startTime[i]]++;
            p[endTime[i]+1]--;
        }
        for(int i = 1; i < 1002; ++i) p[i] += p[i-1];
        return p[queryTime];
    }
};