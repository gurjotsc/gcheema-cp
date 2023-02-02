class Solution {
    func rearrangeArray(_ nums: [Int]) -> [Int] {
        var neg = 0, pos = 0
        var i = 0, parity = 1
        let n = nums.count
        var res = Array(repeating: 0, count: n)
        while i < n {
            if parity == 1 {
                while nums[pos] < 0 {
                    pos += 1
                }
                res[i] = nums[pos]
                pos += 1
            }
            else {
                while nums[neg] > 0 {
                    neg += 1
                }
                res[i] = nums[neg]
                neg += 1
            }
            i += 1
            parity = (parity+1)%2
        }
        return res
    }
}