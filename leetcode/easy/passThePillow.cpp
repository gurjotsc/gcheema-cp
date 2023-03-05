class Solution {
public:
    int passThePillow(int n, int time) {
        int turns = time/(n-1);
        int left = time%(n-1);
        return (!(turns%2)) ? left+1 : n-left;
    }
};