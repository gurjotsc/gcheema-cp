class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> a(arr);
        unordered_map<int, int> rank;
        sort(a.begin(), a.end());
        int r = 1;
        for(int i = 0; i < n; ++i) {
            if(i && a[i] == a[i-1]) continue;
            else rank[a[i]] = r++;
        }
        for(int i = 0; i < n; ++i) arr[i] = rank[arr[i]];
        return arr;
        
        
        
    }
};