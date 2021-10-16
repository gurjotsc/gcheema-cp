class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> p(2); //you only need two rows, one to store the pervious row and the row you are calculating
        p[0].push_back(1);
        int i = 1;
        int count = 0;
        //i is going to alternate between 0 and 1 indicating what row is the current row we are updating
        while (count < rowIndex) {
            int temp = (!i) ? i + 1 : i - 1; //temp tell you what the previous row is
            p[i].push_back(1);
            for(int j = 0; j < p[temp].size() - 1; ++j) {
                //calculate all the values in row i, except for edge ones
                p[i].push_back(p[temp][j] + (p[temp][j+1]));
            }
            p[i].push_back(1);
            //reset the array used for calulcation so it can now be used as the current node
            p[temp].clear();
            i = (!i) ? i = 1 : i = 0; //alternate i
            ++count; //keep track of what node we are on
        }

        return (!i) ? p[1] : p[0]; //return whatever the previous node calulated was (since i is alternated at the end of the while loop we want the previous i to be calculated)
    }
};
