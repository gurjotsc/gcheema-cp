class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res (n);
        //increment i to represent giving 1 candy to the first, 2 to the second, and n+1 again to the first and so on.
       for(int i = 0; candies > 0; ++i) {
           //res[i%n] will just cycle through n ppl
           res[i%n] += min(candies, i+1); //give them i + 1 candies (since i i is 0 indexed) or give them candies if there are less candies than you are suppose to give.
           candies -= i+1; //decrement candies appropriatley
       }
        return res;
    }
};
