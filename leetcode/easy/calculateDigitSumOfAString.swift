class Solution {
    func digitSum(_ st: String, _ k: Int) -> String {
        var s = st
        func digSum(_ s: String) -> Int {
            var res = 0
            for i in s {
                // print(type(of: i.wholeNumberValue))
                res += i.wholeNumberValue!
            }
            return res
        }
        while s.count > k {
            print(s)
            let n = s.count
            var newS: String = ""
            var l = 0
            var r = k-1
            while r < n {
                let idxL = s.index(s.startIndex, offsetBy: l)
                let idxR = s.index(s.startIndex, offsetBy: r)
                let range = idxL...idxR
                var curr = s[range]
                newS += String(digSum(String(curr)))
                l = r+1
                r += k
                if r >= n && l < n {r = n-1}
            }
            s = newS
        }
        return s
    }
}