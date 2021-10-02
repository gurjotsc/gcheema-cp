class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() -1, carry = 0; //carry stores if we have a one and a one in both a and b and we need to carry it over to another bit
        string ans = "";
        while(i >= 0 || j >= 0 || carry >=  1) { //keep running until you have completed indexing both arrays or is there is still a carry left after checking the lasst index
            if(i >= 0) {
                carry += a[i] - '0'; //Increase carry by the value in a
                --i;
            }

            if(j >= 0) {
                carry += b[j] - '0'; //Increase carry by the value in b
                --j;
            }

            //Add whatever carry is modded by 2 (in this case if the carry is tqo we would add 0 because the 1 being carried would get added in the next iteration of the loop)
            // We add the char to ans so that it getting placed at the beginning of the string, ans += ... would place it at the end
            ans = char(carry%2 + '0') + ans;
            carry /= 2; //if carry is 0 or 1 then carry becomes zero, else it becomes 1 so that we can carry to the next bit.
        }
        return ans;
    }
};
