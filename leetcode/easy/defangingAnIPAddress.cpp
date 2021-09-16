class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        //Copy the address to ans as you iterate through address, replacing any '.' with "[.]"
        for(int i = 0; i < address.size(); ++i) {
            if(address[i] == '.') ans += "[.]";
            else ans += address[i];
        }
        return ans;
    }
};
