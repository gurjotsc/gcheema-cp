class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        //The idea here is you always want to take the most valuable jumps. If you get to a position, from the position, jump to the idx that will get you the farthest next
        //i.e
        //2 3 1 1 4
        //  3 1 
        // 3 can get you to 4 faster because 1+nums[1] > 2+nums[2]
        //the max idx for a jump in a range (say nums[0]'s range is from idx 1 - 2, if nums[0] was 4 then its range would be from idx 1-4) is calculated as i + nums[i];
        int res = 1; //you need to take the first jump
        int currIdx = nums[0]; //the max idx you can jump to at the beginning. Will always store the farthest you can get for the least jumps.
        int maxIdxForAJump = nums[0];//The running max idx you can jump to for all the idxs between currIdx and currIdx+nums[currIdx]
        for(int i = 0; i < n; ++i) {
            maxIdxForAJump = max(maxIdxForAJump, i + nums[i]); //max of this and the cureent idx you are at plus how far you can jump from there
            if(currIdx == i && i != n-1) { //you can't jump any farther than the idx you are at
                //i != n-1 because you don't need to jump if you've reached the end
                currIdx = maxIdxForAJump; //jump to the most valuble idx
                ++res; //you took a jump
            }
        }
        return res;
    }
};