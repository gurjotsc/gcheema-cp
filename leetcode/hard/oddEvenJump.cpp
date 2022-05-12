class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> higher(n), lower(n); //for an index i, higher and lower of i store wether or not you can get to the end if thats a higher or lower (odd or even, respectivley) jump at that idx
        higher[n-1] = lower[n-1] = true; //if you're are the end, you did it!
        
        map<int, int> m; //arr[i] = i
        m[arr[n-1]] = n-1;
        int res = 1; //last idx counts
        for(int i = n-2; i >= 0; --i) {
            //if there is an element >= arr[i] that comes after i
            //then higher jump at i will require lower jump at the next element (hi->second)
            auto hi = m.lower_bound(arr[i]); 
            if(hi != m.end()) higher[i] = lower[hi->second]; 
            
            //if there is an element <= arr[i] that comes after i
            //then lower jump at i will require higher jump at the element ((--lo)->second)
            // we use --lo becasue lo will be the first number > arr[i];
            //by doing --lo we access the first number <= arr[i]
            
            auto lo = m.upper_bound(arr[i]);
            if(lo != m.begin()) lower[i] = higher[(--lo)->second];
            // auto lo = m.lower_bound(arr[i]);
            // if(lo->first == arr[i]) lower[i] = higher[lo->second];
            // else if (lo->first > arr[i] && lo != m.begin()) lower[i] = higher[(--lo)->second];
            
            if(higher[i]) ++res; //if higher[i] == true, then it can be a starting idx since we start with a higher jump
            m[arr[i]] = i; //in case there is a lot of the same number, always store the smallest "j" just in case the same number appears at a lower idx where this will be the j we search for
        }
        return res;
    }
};