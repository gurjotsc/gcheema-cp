class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        unsigned long long xyz = n, place = 1;
        //xyzdabc
        while(xyz) {
            int d = xyz%10;
            xyz /= 10;
            res += (xyz*place);
            if(d == 1) res += (n%place)+1; //abc+1
            else if(d > 1) res += place;
            place *= 10;
        }
        return res;
    }
};