class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s2.size();
        int x_y = 0, y_x = 0;
        if(s1.size() != n) return -1;
        //x_y stores x's in s1 with mismatch, y_x stores the same for y's
        for(int i = n-1; i >= 0; --i) {
            if(s2[i] == s1[i]) continue;
            else if(s1[i] == 'x') ++x_y;
            else ++y_x;
        }
        //case 1: x x        one swap
        //        y y
        //case 2: y y        one swap
        //        x x
        //case 3: x y        two swap
        //        y x
        //case 4: y x        two swap
        //        x y
        //The following aren't needed but help understand the problem
        //case 5: x x x (y)      -1
        //        y y y (x) this is the same issue where there is no other pair to swap with
        //case 6: y y y (x)      -1
        //        x x x (y) this is the same issue where there is no other pair to swap with
        //case 7: x x x y      three swaps
        //        y y y x
        //         1   2
        //case 8: y y y x      three swaps
        //        x x x y
        //         1   2
        //so now if you mod both x_y and y_x and they are both 0 then you have a whole bunch case 1 and 2 (hence the x_y/2 and y_x/2 in the return). Then if you add the mods of both of them you are getting 0. In the case where you mod both and both are 1 (case 3 and 4), then you want to add thier mod values as well since x_y%2 + y_x%2 == 1+1 and it takes two swaps to perform this. Just add together the number of cases of 1-4 basically or return -1 when the condition is not met.
        return (!((x_y + y_x)  % 2)) ? ((x_y / 2) + x_y % 2 + (y_x / 2) + y_x % 2) : -1;
    }
};
