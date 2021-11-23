class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOccurance(26, INT_MAX);
        vector<int> lastOccurance(26);
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            firstOccurance[s[i] - 'a'] = min(firstOccurance[s[i] - 'a'], i);
            lastOccurance[s[i] - 'a'] = i;
        }
        //count the number of unique character between to occurances of a letter
        for(int i = 0 ; i < 26; ++i) {
            if(firstOccurance[i] < lastOccurance[i]) {
                //stores every unique chracter between the first and last occurance of each letter
                unordered_set<char>seen(begin(s) + firstOccurance[i]+1, begin(s) + lastOccurance[i]);
                ans += seen.size();
            }
        }
        return ans;
    }
};
