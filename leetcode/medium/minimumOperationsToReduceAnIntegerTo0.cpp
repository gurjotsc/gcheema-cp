class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        while(n) {
            if((n&0b11) == 0b11) { //if the begining has multiple ones
                ++n; //add 2^0 to n so the beginning of n goes from ...11111111 to ...10000000
                ++res;
            }
            else {
                res += (n&0b1);
                n >>= 1;
            }
        }
        return res;
    }
};