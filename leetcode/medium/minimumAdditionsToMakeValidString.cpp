class Solution {
public:
    int addMinimum(string w) {
        int res = 0, n = w.size();
        int k = 0, prev = 'z';
        for(auto c : w) {
            k += (c <= prev); //increment k when we find an invalid (non increasing) substring
            prev = c;
        }
        return (k*3)-n; //return the length it should be minus how many charachters there are already in w


        //Also works
        // for(int i = 0; i < n; ++i) {
        //     if(w[i] == 'a') {
        //         if(i == n-1) res += 2;
        //         else if(w[i+1] == 'b') {
        //             if(i+1 == n-1) {
        //                 ++res;
        //                 ++i;
        //             }
        //             else if(w[i+2] == 'c') i += 2;
        //             else {
        //                 ++res;
        //                 ++i;
        //             }
        //         }
        //         else if(w[i+1] == 'c') {
        //             ++res;
        //             ++i;
        //         }
        //         else res += 2; //i+1 is 'a'
        //     }
        //     else if(w[i] == 'b') {
        //         if(i == n-1) res += 2;
        //         else if(w[i+1] == 'c') {
        //             ++res;
        //             ++i;
        //         }
        //         else res += 2;
        //     }
        //     else res += 2;
        // }
        // return res;
    }
};
