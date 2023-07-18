class Solution {
public:
    int pivotInteger(int n) {
        if(trunc(sqrt((pow(n, 2)+n)/2)) == sqrt((pow(n, 2)+n)/2))
            return sqrt((pow(n, 2)+n)/2);
        return -1;
    }
};