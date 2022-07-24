class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        set<int> s1(begin(ranks), end(ranks));
        set<char> s2(begin(suits), end(suits));
        if(s2.size()==1) return "Flush";
        for(auto r : ranks) {
            int cnt = 0;
            for(auto i : ranks) cnt += (i == r);
            if(cnt >= 3) return "Three of a Kind";
        }
        if(s1.size() <= 4) return "Pair";
        return "High Card";
    }
};