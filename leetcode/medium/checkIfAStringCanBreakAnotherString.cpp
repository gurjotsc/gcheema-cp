class Solution {
public:
    bool check(const vector<int>& f1, const vector<int>& f2) {
        //you're checking if f2 can break f1
        int diff = 0;
        for(int i = 0; i < 26; ++i) {
            diff += (f1[i]-f2[i]);
            if(diff < 0) return false; //If this occurs, that means that there are more bigger letters in f2 than f1
            //say aaaaa = f1
            //    cccca = f2
            //Then the first iteration, diff will be 4, and on the second it will be 0 and we return true
            //now aaaaa = f2
            //    cccca = f1
            //Then the first iteration, -4, we return false since we have enough info to know that f1 has 4 bigger letters
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        vector<int> f1(26), f2(26);
        for(int i = 0; i < n; ++i) {
            ++f1[s1[i]-'a'];
            ++f2[s2[i]-'a'];
        }
        return check(f1, f2) || check(f2, f1);
    }
};