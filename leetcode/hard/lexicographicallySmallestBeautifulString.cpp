class Solution {
public:
    inline bool valid(int i, const string& s) { 
        return (i < 1 || s[i] != s[i-1]) && (i < 2 || s[i] != s[i-2]);
    }
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        for(int i = n-1; i >= 0; --i) {
            ++s[i];
            while(!valid(i, s)) ++s[i];
            if(s[i] < 'a'+k) {
                for(int j = i+1; j < n; ++j) {
                    s[j] = 'a';
                    while(!valid(j, s)) ++s[j];
                    //No need for the following check here because k >= 4.
                    //We know that s[j-1] and s[j-2] are valid because s is beautiful
                    //That means that there will be a valid letter (say aba and j = 2), then k would allow up to d. If it was dcd then s[j]=a before the while loop would be valid since it would be dca.
                    // if(s[i] < 'a'+k)
                }
                return s;
            }
        }
        return "";
    }
};