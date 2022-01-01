class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k);
        unordered_map<int, unordered_set<int>> m; //map ids to unique minutes
        for(auto& i : logs) {
            m[i[0]].insert(i[1]); //insert the minute into the id's set (won't insert duplicates)
        }
        for(auto& j : m) {
            ++res[j.second.size()-1]; //the size of j is the number of unique mins since its a unique set
            //-1 because its 1-indexed
        }
        return res;
    }
};
