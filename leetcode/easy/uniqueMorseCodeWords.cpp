class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> res;
        for(auto s : words) {
            string temp = "";
            for(auto c : s) {
                temp += morse[c-'a'];
            }
            res.insert(temp);
        }
        return res.size();
    }
};
