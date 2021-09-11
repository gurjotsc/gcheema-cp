class Solution {
public:
    bool rotateString(string s, string goal) {
        //creates two vectors to store the next and previous letters for both s and goal
        vector<pair<char, char>> check;
        vector<pair<char, char>> check2;
        //iterate through s and store the letters surrounding s[i]
        for(int i = 0; i < s.size(); ++i) {
            if(!i) check.push_back(make_pair(s[s.size() - 1], s[i + 1]));
            else if(i == s.size() - 1) check.push_back(make_pair(s[i - 1], s[0]));
            else check.push_back(make_pair(s[i - 1], s[i + 1]));
        }
        //iterate through goal and store the letters surrounding goal[i]
        for(int j = 0; j < goal.size(); ++j) {
            if(!j) check2.push_back(make_pair(goal[goal.size() - 1], goal[j + 1]));
            else if(j == s.size() - 1) check2.push_back(make_pair(goal[j - 1], goal[0]));
            else check2.push_back(make_pair(goal[j - 1], goal[j + 1]));
        }
        //Regardless of the rotation of the word, if they are rotatble, the letters that come before and after
        //each letter have to be the same

        //If we sort the two vectors they should sort by the first letter in the pair
        //which means they will equal each other since they will have all the same pairs if s is rotable to
        //goal
        sort(check.begin(), check.end());
        sort(check2.begin(), check2.end());

        return check == check2;
    }
};
/*
s = "abcde", goal = "cdeab"
check
eb
ac
bd
ce
da
    These both become this:
    ac
    bd
    ce
    da
    eb
check2
bd
ce
da
eb
ac
*/
