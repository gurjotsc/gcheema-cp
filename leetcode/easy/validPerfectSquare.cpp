class Solution {
public:
    bool isPerfectSquare(int num) {
        // Declare lo and hi for binary search. hi can't be higher than num cuz sqrt(num) < num

        int lo = 0; int hi = num;
        //If lo crosses hi that means no integer exists that is sqrt(num)
        //Self-Explanatory Binary Search

        while(lo <= hi) {
            long mid = lo + (hi - lo)/2; //We use long because mid*mid could overflow if mid > sqrt(x)
            if(mid*mid == num) return true;
            else if(mid*mid > num) hi = mid - 1;
            else lo = mid + 1;
        }

        //If nothing found then return false
        return false;
    }
};
