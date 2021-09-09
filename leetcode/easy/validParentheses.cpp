class Solution {
public:
    //create a stack that pushes open parantheses and pops them when it sees the oppisite
    stack<char> st;
    bool isValid(string s) {
        //Iterate through the string
        for(auto c : s) {
            //If its the first letter just push it (or else you'll get an address santizer (out-of-bounds) error when you check the st.top() consdition)
            if(st.empty()) st.push(c);
            //Push open parentheses
            else if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // pop if its the closing parentheses
            else if((c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '['))       {
                st.pop();
            }
            //return false if it doesn't meatch the st.top()
            else {
                return false;
            }
        }
        //If all the parentheses weren't closed it'll return false, else true
        return st.empty();
    }
};
