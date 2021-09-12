class Solution {
public:
    bool judgeSquareSum(int c) {
        //Unnecessary because you are given a non-negative integer, but okay
        if(c < 0) return false;
        //Set Two Pointers to equal the least possible value and the highest possible value
        int l = 0; int r = (int)sqrt(c);
        //These two integers will increment/decrement their values until l is greater than r or until you
        //find two integers that work
        while(l <= r) {
            //Create a long that stores the current check
            long temp = (long)(l*l) + (r*r);
            //Either increment l if its too small or decrement r or return true if temp == c
            if(temp < c) ++l;
            else if(temp > c) --r;
            else return true;
        }
        //If l is bigger than r that means you found no viable integer
        return false;
    }
};
