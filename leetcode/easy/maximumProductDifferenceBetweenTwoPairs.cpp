class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int w = INT_MIN, x = INT_MIN, y = INT_MAX, z = INT_MAX;
        //iterate through nums and store the top two and bottom two
        for(auto i : nums) {
            if(i > w) {
                x = w;
                w = i;
            }
            else if (i > x) { //if you i is bigger than.x, but not w (cuz then the i > w won't                                   get trggered, but x needs to store the second lowest value)
                x = i;
            }
            if (i < y) {
                z = y;
                y = i;
            }
            else if (i < z) { //same as i > x consdition, but for second min
                z = i;
            }
        }

        return (w*x) - (y*z);
    }
};
