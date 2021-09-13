class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int M = flowerbed.size();
        //Iterate through the entire vector and check to see if each index has an adjacent flower or not
        //Decremant n if it doesn't have adjacent flowers
        for (int z = 0; z < M; ++z) {
            if (flowerbed[z] == 0) {
                int l = z-1, r = z+1;
                if ((l < 0   || flowerbed[l] == 0) &&
                    (r >= M  || flowerbed[r] == 0)) {
                    --n;
                    flowerbed[z] = 1;
                }
            }
        }
        //If all flowers were placed then return true, else false
        return n <= 0;
    }
};
