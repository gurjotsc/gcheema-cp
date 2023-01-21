class Solution {
    func isSameAfterReversals(_ num: Int) -> Bool {
        var s = String(num)
        let n = s.count
        let first = (s[s.index(s.startIndex, offsetBy: n-1)] != "0") 
        let second = (String(s.reversed().reversed()) == s)
        return (num == 0) || (first && second)
    }
}