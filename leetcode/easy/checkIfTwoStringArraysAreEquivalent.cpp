class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0; //iteraator for each string in word
        int w1 = 0, w2 = 0; //word iterator
        //just iterate through each character of both word vectors and return false if its different
        while(w1 < word1.size() && w2 < word2.size()) {
            if(word1[w1][i++] != word2[w2][j++]) return false;
            if(i >= word1[w1].size()) {
                i = 0;
                ++w1;
            }
            if(j >= word2[w2].size()) {
                j = 0;
                ++w2;
            }
        }
        //if one didn't finish iterating, then you know that the words cannot be equal
        //for this to return true, they should finish iterating together
        return w1 == word1.size() && w2 == word2.size();
    }
};
