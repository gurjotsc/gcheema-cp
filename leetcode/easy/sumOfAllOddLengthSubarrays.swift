class Solution {
    func sumOddLengthSubarrays(_ arr: [Int]) -> Int {
        let n = arr.count
        var res = 0
        for i in 0...n-1 {
            for j in stride(from: i, to: n, by: 2) {
                res += arr[i...j].reduce(0, +)
            }
        }
        return res
    }
}