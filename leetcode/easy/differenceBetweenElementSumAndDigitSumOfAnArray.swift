class Solution {
    func differenceOfSum(_ nums: [Int]) -> Int {
        var es = 0
        var ds = 0
        es = nums.reduce(0, +)
        for i in nums {
            for j in String(i) {
                ds += j.wholeNumberValue!
            }
        }
        return abs((es-ds))
    }
}