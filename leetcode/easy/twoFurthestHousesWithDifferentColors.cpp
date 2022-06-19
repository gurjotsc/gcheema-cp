class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int l = 0, r = n-1;
        int res = 0;
        while(colors[0] == colors[r]) r--;
        while(colors[l] == colors[n-1]) l++;
        return max((n-1)-l, r);
    }
};