class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        bool lo = false, upp = false, dig = false, spec = false;
        string temp = "!@#$%^&*()-+";
        set<char> s(temp.begin(), temp.end());
        if(n < 8) return false;
        for(int i = 1; i < n; ++i)
            if(password[i] == password[i-1]) return false;
        for(auto& c : password) {
            if(isupper(c)) upp = true;
            if(islower(c)) lo = true;
            if(isdigit(c)) dig = true;
            if(s.count(c)) spec = true;
        }
        
        return (upp && lo && dig && spec);
        
        
    }
};