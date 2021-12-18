class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int aScore = 0;
        int bScore = 0;
        int n = aliceValues.size();
        vector<vector<int>> sumScore(n , vector<int>(3));
        char turn = 0; //bob is 1
        //the sumScore will store both the value of picking a stone, as well as removing that stone from the opponent's choices on their turn
        for(int i =0; i < n; ++i) {
            sumScore[i] = {aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]};
        }

        sort(sumScore.begin(), sumScore.end());

        for(int i = n-1; i >= 0; --i) {
            turn %= 2;
            if(!turn) aScore += sumScore[i][1]; //store alices Score
            else bScore += sumScore[i][2]; //store bob's Score
            ++turn;
        }

        if(aScore > bScore) return 1;
        else if(bScore > aScore) return -1;
        else return 0;
    }
};
