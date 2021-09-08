class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //Create a map to map all edges from a garden to an integer <int, vector<int>>
        unordered_map<int, vector<int>> m;
        //Stores the flower in the next garden (i+1)th
        vector<int> ans(n);
        //Maps all direections to and from to the map;
        for(auto& p:paths) {
            m[p[0]].push_back(p[1]);
            m[p[1]].push_back(p[0]);
        }
        //Starting from the first flower to the last, check to see if a connected flower is using a certain color, if not then use the first open color on that flower
        //We start i at one since thats what the problem indexes by i.e. the first flower is indexed at 1 not 0
        for(int i = 1; i <= n; ++i) {
            //Creates a color array
            vector<int> colors(5,0);
            //For every flower connected to the flower you are currently iterating on, check to see what colors they have.
            //Remember ans stores the a+1th flower color hence we subtract by one.
            //*NoteIf the flower hasn't been placed yet then ans[a-1] is just 0
            for(auto a:m[i]) {
                colors[ans[a-1]] = 1;
            }
            //Checks to see the first available color and assign it
            for(int j = 1; j < 5; ++j) {
                if(!colors[j]) {
                    ans[i-1] = j;
                    break;
                }
            }
        }

        return ans;
    }
};
