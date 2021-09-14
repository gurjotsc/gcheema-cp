class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; int j = s.size() - 1;

        //OIerate throught the entire string checking for alphanumeric characters and comparing them
        //The reason its not i <=j is because if they are equal then you know that that character is the same
       for(;i < j;) {
           if(!isalnum(s[i])) ++i; //Check alphanum and break (aka the other else ifs won't get triggerd)
           else if(!isalnum(s[j])) --j; //Check alphanum and break (aka the other else if won't get triggerd)
           else if(tolower(s[i++]) != tolower(s[j--])) return false; //if the current characters are equal, compare them and increment/decrement
       }

        return true;
    }
};
