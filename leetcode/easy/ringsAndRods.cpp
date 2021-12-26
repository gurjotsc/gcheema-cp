class Solution {
public:
    int countPoints(string rings) {
        vector<int> rods(10);
        int res = 0;
        for(int i = 0; i < rings.size(); i+=2) {
            switch(rings[i]) {
                    case('R'):
                        rods[rings[i+1] - '0'] |= 1; // bit that represents red
                        break;
                    case('G'):
                        rods[rings[i+1] - '0'] |= (1 << 1); // bit that represents green
                        break;
                    case('B'):
                        rods[rings[i+1] - '0'] |= (1 << 2); // bit that represents bluw
                        break;
            }
        }

        for(auto i : rods) {
            res += (i == 7) ? 1 : 0; //all the color conditions were met, then the number stored at the index should be 7
        }
        return res;
    }
};
