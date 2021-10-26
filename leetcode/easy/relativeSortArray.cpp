class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001] = {0}; //values can't be higher than 1000 so this stores the frequency                                  of each number at the corresponding index
        for(int i : arr1) ++count[i]; //update the frequency accordingly
        int i = 0; //what index we are placing a sorted value in arr1
        for(int j : arr2) {
            //while the frequency is > 0
            while(count[j] > 0) {
                arr1[i] = j; //set the value of arr1[i] to j in arr2
                ++i; //increment i so we can move onto the next index in arr1
                --count[j]; //decrement the frequency
            }
        }
        //run through all indexes to see whats left
        for(int j = 0; j < 1001; ++j) {
            //only runs the following (same as previous loop) if a value in arr1 that is not in               arr2 is found. Then sorts these in asending order
            //while the frequency is > 0
            while(count[j] > 0) {
                arr1[i] = j;
                ++i;
                --count[j];
            }
        }
        return arr1;
    }
};
