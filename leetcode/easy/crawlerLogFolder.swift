class Solution {
    func minOperations(_ logs: [String]) -> Int {
        var res = 0
        for i in logs {
            if i == "../" {
                res -= 1
            }
            else if i != "./" {
                res += 1
            }
            res = max(0, res)
        }
        return res
    }
}