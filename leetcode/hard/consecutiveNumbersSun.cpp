class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int n = 1;
        int res = 0;
        int start = ((2*N - pow(n,2)+n)/(2*n));
        while(start > 0) {
            //check if start is an integer. If it is, there exists a number x where
            // x + (x+1) + (x+2) +...+ (x+(n-1)) = N
            // Thus
            // xn + (((n-1)*n)/2) = N
            // x = ((2*N - pow(n,2)+n)/(2*n))
            if(!(start - ((2*N - pow(n,2)+n)/(2*n)))) ++res;
            ++n;
            start = ((2*N - pow(n,2)+n)/(2*n));
        }
        
        return res;
    }
};