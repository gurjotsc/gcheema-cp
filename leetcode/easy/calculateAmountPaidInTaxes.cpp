class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int income) {
        double res = 0, prevTaxedIncome = 0;
        for(auto& i : b) {
            res += max(0.0, (((min(income, i[0]) - prevTaxedIncome)*((double)i[1]/100))));
            prevTaxedIncome = i[0];
        }
        return res;
    }
};