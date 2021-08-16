class Solution {
public:
    bool rotateString(string s, string goal) {
        vector<pair<char, char>> check;
        vector<pair<char, char>> check2;
        for(int i = 0; i < s.size(); ++i) {
            if(!i) check.push_back(make_pair(s[s.size() - 1], s[i + 1]));
            else if(i == s.size() - 1) check.push_back(make_pair(s[i - 1], s[0]));
            else check.push_back(make_pair(s[i - 1], s[i + 1]));
        }

        for(int j = 0; j < goal.size(); ++j) {
            if(!j) check2.push_back(make_pair(goal[goal.size() - 1], goal[j + 1]));
            else if(j == s.size() - 1) check2.push_back(make_pair(goal[j - 1], goal[0]));
            else check2.push_back(make_pair(goal[j - 1], goal[j + 1]));
        }

        sort(check.begin(), check.end());
        sort(check2.begin(), check2.end());

        return check == check2;
    }
};
