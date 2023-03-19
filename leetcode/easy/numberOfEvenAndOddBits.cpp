class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        int i = 0;
        while(n) {
            if(n & 1) {
                even += (!(i%2));
                odd += ((i%2));
            }
            ++i;
            n >>= 1;
        }
        return {even, odd};
    }
};