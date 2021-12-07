class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        int n = word.size();
        //just iterate through everything in patterns and then use word.find() to see if its a substring
        for(auto p : patterns) {
            if(word.find(p) != string::npos) ++res;
        }
        return res;
    }
};
