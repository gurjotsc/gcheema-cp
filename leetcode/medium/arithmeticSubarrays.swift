class Solution {
    func checkArithmeticSubarrays(_ nums: [Int], _ left: [Int], _ right: [Int]) -> [Bool] {
        let n = nums.count, m = left.count
        var res: [Bool] = []
        for (l,r) in zip(left, right) {
            var sub = nums[l...r].sorted()
            var diff = sub[1]-sub[0]
            var curr: Bool = true
            for i in 1...sub.count-1 {
                guard sub[i]-sub[i-1] == diff else {
                    curr = false
                    break
                }
            }
            res.append(curr)
        }
        return res
    }
}