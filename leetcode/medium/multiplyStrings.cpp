class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<string> sum;
        string res;
        
        for (int j = m-1; j >= 0; --j) {
            int store = 0;
            string line;
            int x = ((m-1)-j);
            while(x) {
                line += '0';
                --x;
            }
            for(int i = n-1; i >= 0; --i) {
                int mult = ((num1[i] - '0') * (num2[j] - '0')) + store;
                if(!i) {
                    string s;
                    while(mult) {
                        s += (char)((mult%10)+'0');
                        mult /= 10;
                    }
                    line += s;
                }
                else line += (char)((mult%10)+'0');
                store = ((mult - (mult%10))/10);
            }
            sum.push_back(line);
        }
        int store = 0;
        for(int i = 0; i < sum[m-1].size(); ++i) {
            int sm = store;
            
            for(auto& j : sum) if(i < j.size())
                sm += (j[i]-'0');
            
            
            res += ((char)((sm%10)+'0'));
            store = ((sm - (sm%10))/10);
            if(i == sum[m-1].size()-1 && store) res += (char)(store+'0');
        }
        
        reverse(begin(res), end(res));
        return res;
    }
};