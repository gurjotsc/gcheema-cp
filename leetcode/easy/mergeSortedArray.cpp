class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        while (n > 0 && i >= 0) {
            if(m > 0 && nums1[m - 1] > nums2[n - 1]) {
                nums1[i--] = nums1[--m];
            }
            else
                nums1[i--] = nums2[--n];
        }

    }
};
