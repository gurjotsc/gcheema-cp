class Solution {
public:
    int maximum69Number (int num) {
        int i = 0;
        int temp = num;
        int sixIdx = -1;
        while(temp) {
            if(temp % 10 == 6) //temp % 10 gets the rightmost digit
                sixIdx = i;
            temp /= 10; //drops the rightmost digit
            ++i; //stores the current index
        }
        if(sixIdx == -1) return num;
        return (pow(10, sixIdx) * 3) + num; //add 3 * the place od sixIdx to turn the 6 to a 9
    }
};
