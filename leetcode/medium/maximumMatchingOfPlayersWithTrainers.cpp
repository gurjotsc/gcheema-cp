class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        int p = 0, t = 0;
        int res = 0;

        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        while(p < n && t < m) {
            if(players[p] <= trainers[t]) {
                ++res;
                ++p;
            }
            ++t;
        }

        return res;
    }
};