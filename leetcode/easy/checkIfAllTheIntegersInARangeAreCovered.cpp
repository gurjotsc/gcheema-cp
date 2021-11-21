class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        //we need two buffers hence the 52 size
        //Index 0 is just gonne be 0 since we are one-indexed
        //Index 51 will just store the "exit" of our range
        vector<int> prefix(52);
        for(auto i : ranges) {
            //Indicate at the start of the range that we are beginning the range here
            ++prefix[i[0]];
            //Indicate AFTER (hence the + 1) the end of the range that we are done with the                   range here
            --prefix[i[1] + 1];
        }

        //Do prefix sum so that the entire array can be populated with 0 (not in a range) or a             num > 0 (representing how many ranges it is in)
        for(int i = 1; i < 52; ++i) prefix[i] += prefix[i-1];

        //If a number in between left and right is in 0 ranges, return false
        for(int i = left; i <= right; ++i) {
          if(!prefix[i]) return false;
        }

        return true;
    }
};
