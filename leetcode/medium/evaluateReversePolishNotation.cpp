class Solution {
public:
    int convert(string& x) {
        int n = x.size();
        int temp = n;
        int res = 0;
        if(x[0] != '-') {
            for(int i = 0; i < n; ++i) {
                int curr = x[i] - '0';
                res += (curr * pow(10, temp-1));
                temp--;
            }
        }
        else if (x[0] == '-') {
            temp--;
            for(int i = 1; i < n; ++i) {
                int curr = x[i] - '0';
                res += (curr * pow(10, temp-1));
                temp--;
            }
            res *= -1;
        }
        return res;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& t : tokens) {
            if(t == "+") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a+b);
            }
            else if(t == "-") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b-a);
            }
            else if(t == "*") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a*b);
            }
            else if(t == "/") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b/a);
            }
            else s.push(convert(t));
        }
        return s.top();
    }
};