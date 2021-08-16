class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        vector<char> arr;
        for(int i = 0; i < s1.size(); ++i) {
            if(s1[i] != s2[i]) arr.push_back(i);
            if(arr.size() > 2) return false;
        }
        if(arr.size() < 2) return false;
        if(s1[arr[0]] == s2[arr[1]] && s1[arr[1]] == s2[arr[0]]) return true;
        else return false;
    }
};
