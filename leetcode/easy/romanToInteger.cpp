class Solution {
public:
    int romanToInt(string s) {
        int ans = 0; //Ans to store the answer of course
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; //Maps all possible roman numerals to their corresponding value
        //When subtracting, we can then just subtract the value of the roman numeral "causing" the subtraction (i.e I in IV)

        //Iterate through the entire string and sum every character's value. If the value is less than the value that came next in the string, subtract the value instead of adding it.
        for(int i = s.size() - 1; i >= 0; --i) {
            if(i < s.size() - 1 && m[s[i]] < m[s[i+1]]) ans -= m[s[i]];
            else ans += m[s[i]];
        }
        return ans;
    }
};
