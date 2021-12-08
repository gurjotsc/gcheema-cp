class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        while(n > 0) {
            //find max
            int idx = 0; int m = arr[idx];
            for(int i = 0; i < n; ++i) {
                if(m != max(m, arr[i])) {
                    m = max(m, arr[i]);
                    idx = i;
                }
            }
            //use the max to reverse the max to the head and then reverse it again to the desired position of (n-1)
            if(idx != n-1) {
                reverse(begin(arr), begin(arr) + idx + 1); //brings max to head
                reverse(begin(arr), begin(arr) + n-1+1); //brings max to the n-1'th position
                res.push_back(idx+1);
                res.push_back(n-1+1);
            }
            --n; //decrement n since the max is already stored in the correct position (i.e the last position holds the max, the n-1th position holds the second largest and so on)
        }

        return res;
    }
};
