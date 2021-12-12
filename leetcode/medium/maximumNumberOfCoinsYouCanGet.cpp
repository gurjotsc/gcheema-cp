class Solution {
public:
    int maxCoins(vector<int>& piles) {
        map<int, int> m;
        int n = piles.size();
        int res = 0;
        int a = n - 1; //alice index
        int y = a - 1; //you index
        int b = 0; //bob indes

        //if you sort the piles, then you want bob to always pick the smallest amount so that you don't exhaust good options for yourself (hence he starts at index = 0). Since Alice must pick the maximum from a pile, she should always pick only one index higher than you
        //if piles will look like this [smallest (bob), second biggest (you), biggest(Alice)]
        sort(piles.begin(), piles.end());

        while(b < y) {
            res += piles[y]; //keep track of your coins
            //update indexes
            a -= 2;
            y = a - 1;
            ++b;
        }
        return res;
    }
};
