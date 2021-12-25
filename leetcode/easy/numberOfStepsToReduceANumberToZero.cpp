class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        if(!num) return 0;
        //in the binary representation, if a number ends with one it is odd and if it ends with 0 then its even. So, we & num with 1 to see if the right most digit is a 1. If its not a one (even) then we want to divide by 2, hence incrementing res by 1. Else if its 1 (odd) then we wan't to subtract by 1 and then divide by 2, hence incrementing res by 2. We then right shift num by 1 place to move on to the next binary digit. Once the leftmost 1 is looked at, num will be 0 and the while loop will close.
        while(num) {
            res += (!(num & 1)) ? 1 : 2;
            num >>= 1;
        }
        //return res - 1 because the last case is always just one so we don't want to subtract one then divide (we only want to subtract 1 to get 0 and that is the only step we take)
        return res - 1;
    }
};
