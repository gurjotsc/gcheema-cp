class Solution {
public:
    int minimumBoxes(int n) {
        int totalBoxes = 0, diameter = 0, extra = 0;
        //run while your current totalBoxes + how many you would add if the diameter increased by 1 is <= n
        //the summation of a number up to k is (k)*(k+1)/2
        //in our case k = the outermost diameter of the pyramid as we we add to current boxes (watch video: https://www.youtube.com/watch?v=h3k-xR9qHRs)
        while(totalBoxes + ((diameter+1) * (diameter+2) / 2) <= n) {
            //each increment we add boxes until we can add another box on the level above using the summation formula.
            totalBoxes += ((diameter+1) * (diameter+2) / 2);
            //increment diameter to get the next diameter
            ++diameter;
        }
        //since the previous condition will be < n - unless its == n - this for loop finds out the extra boxes you need to add to the floor.
        while(totalBoxes < n) {
            totalBoxes += ++extra; //since you increment by something thats being incremented, you are incrementing totalboxes by 1, then 2,3,4,5... becasue each time you go across the outermost diameter, you can add one box, then you would add two, then three (just watch the youtube video linked above). Extra would then conveniently hold how many extra are added at the bottom
        }
        //since diameter is the outermost diameter, return the sum of all the blocks up to the diameter + any extra blocks you had to use
        //1+2+3+4+...+diameter+extra = (diameter*(diameter+1)/2) + extra
        return (diameter * (diameter+1) / 2) + extra;


    }
};

/*
1 1


*/
