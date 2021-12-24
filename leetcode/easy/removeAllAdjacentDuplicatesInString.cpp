class Solution {
public:
    string removeDuplicates(string s) {
        int j = 0;
        //iterate through the string once and edit the string s using two pointers
        //if you see a duplicate in the substring you are editing, then move j back by 2 and continue editing the substring, (thus changing the two duplicates you "removed")
        //by doing j-=2, in the case where there is a duplicate in between a duplicate, such as "abba", you can start again at the character before "bb" to see if its a duplicate (note we use  -= 2 to account for the ++j in the for loop)
        //return the substring up to j at the end since that part of the string will contain all of the non duplicate characters
        for(int i = 0; i < s.size(); ++i, ++j) {
            s[j] = s[i];
            if(j > 0 && s[j] == s[j-1])
                j -= 2;
        }
        return s.substr(0, j);
    }
};
