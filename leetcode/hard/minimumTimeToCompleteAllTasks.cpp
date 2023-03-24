class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        vector<int> on(2002);
        sort(begin(tasks), end(tasks), [&] (const auto a, const auto b){
            return a[1] < b[1];
        });

        for(auto& t : tasks) {
            int start = t[0], end = t[1], dur = t[2];
            dur -= count(begin(on)+start, begin(on)+end+1, 1); //end+1 because the range is [first, last)
            for(int i = end; dur > 0; --i) {
                dur -= !on[i];
                on[i] = 1;
            }
        }

        return count(begin(on), end(on), 1);
    }
};