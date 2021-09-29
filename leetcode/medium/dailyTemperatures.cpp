class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> ans (N);

        //iterate down temperatures
        for(int i = N - 1; i >= 0; --i){
            int j = i+1; //j is the next index
            //iterate from j through temperatures to find a value of temperatures[j] > temperatures[i]
            //*Note this is considered O(N) since you are skipping through the array (I think O(N^2)) in worst case - see discussion
            while(j < N && temperatures[j] <= temperatures[i]) {
                if (ans[j] > 0) j = ans[j] + j; //If we know the next warmer day from ans[j] we know that no index until that day will satisfy this so we can move j to that index of the next warmer day to see if it is greater than day i
                else j = temperatures.size();//If there is no warmer day after day j
            }
            if(j < N) ans[i] = j - i; //If j is in temperatures we just set ans[i] = the index of the next warmer day minus the index i
        }

        return ans;
    }
};
