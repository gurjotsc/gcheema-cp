class Solution {
public:
    static constexpr int N = 1e5+1;
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> res;
        const long long n = nums1.size();
        //the reason we can't use bitset<N> bs(s) where s is a binary string is because the constructore reverses it
        //i.e bitset<4> bs("1101") == [1,1,0,1]
        //we need the following
        //i.e bitset<N> bs(0);
        //    for(int i = 0; i < n; ++i) bs1[i] = nums1[i]; == [1,0,1,1]
        //this is because bitset is indexed backwords. bs[0] corresponds to the rightmost bit
        bitset<N> bs(0);
        for(int i = 0; i < n; ++i) bs[i] = nums1[i];
        bitset<N> init(0);
        init.flip();
        unsigned long long sum = accumulate(begin(nums2), end(nums2), 0ll);

        for(const auto& q : queries) {
            if(q[0] == 1) {
                unsigned long long sz = q[2]-q[1]+1;
                bitset<N> temp(init<<sz);
                temp = ~temp;
                temp <<= q[1];
                bs ^= temp;
            }
            else if(q[0] == 2) sum += (q[1] * bs.count());
            else res.push_back(sum);
        }


        return res;
    }
};