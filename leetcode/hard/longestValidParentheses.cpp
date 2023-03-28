class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int res = 0;
        st.push(-1);

        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();

                //this is going to be used to find the size and mark the start of the next string
                if(st.empty()) st.push(i); 
                else res = max(res, i-st.top());
            }
        }

        return res;
    }
};