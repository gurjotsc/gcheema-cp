class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //If the target is bigger than all letters in the list (this wraps around as defined by the problem) or all letters are bigger than the target then just return the smallest integer
        if(letters[letters.size() - 1] <= target || target < letters[0]) return letters[0];
        //Declare lo and hi for binary serach over letters
        int lo = 0; int hi = letters.size() - 1;
        //iterate until lo crossed hi or they are equal
        while(lo < hi) {
            //declare the midpoint
            int mid = lo + (hi - lo)/2;
            //if mid is one letter higher than the target then that is the only possible answer so we return it
            if(letters[mid] == target + 1) return letters[mid];
            //else reduce hi if letters[mid] is too big
            //*Note its not mid - 1 since you don't know if letters[mid-1] is actually less than target, hence letters[mid] could still be the answer
            else if(letters[mid] > target) hi = mid;
            //In this case we do incrase mid by 1 since we know mid is less than target and hence not viable
            else lo = mid + 1;
        }
        //Just return whatever lo is since its the best viable solution
        return letters[lo];
    }
};
