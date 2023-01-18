class Solution {
    func longestConsecutive(_ nums: [Int]) -> Int {
        let n = nums.count
        let s = Set(nums)
        var res = 0
        for i in nums {
            if !s.contains(i-1) {
                var x = i+1
                while s.contains(x) {x += 1}
                res = max(res, x-i)
            }
        }
        return res
    }
}