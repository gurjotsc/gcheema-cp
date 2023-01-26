class Solution {
    func minBitFlips(_ start: Int, _ goal: Int) -> Int {
        var s = String(start, radix: 2)
        var g = String(goal, radix: 2)
        if g.count < s.count {
            g = String(Array(repeating: "0", count: s.count-g.count)) + g
        }
        else if s.count < g.count {
            s = String(Array(repeating: "0", count: g.count-s.count)) + s
        }
        let n = s.count
        var res = 0
        for i in 0...n-1 {
            if s[s.index(s.startIndex, offsetBy: i)] != g[g.index(g.startIndex, offsetBy: i)] {
                res += 1
            }
        }
        return res
    }
}