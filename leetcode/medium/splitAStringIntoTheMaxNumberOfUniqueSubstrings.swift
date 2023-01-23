class Solution {
    func maxUniqueSplit(_ s: String) -> Int {
        // var st: Set<String> = []
        var res = 1
        let n = s.count
        func recurse(_ used: Set<String> = [], _ start: Int = 0) {
            var u = used
            guard start < n else {
                res = max(res, u.count)
                return
            }

            for r in start...n-1 {
                let idxR = s.index(s.startIndex, offsetBy: r+1)
                let idxL = s.index(s.startIndex, offsetBy: start)
                let range = idxL..<idxR
                
                guard !u.contains(String(s[range])) else {continue}
                u.insert(String(s[range]))
                recurse(u, r+1)
                u.remove(String(s[range]))
            }
        }
        recurse()
        return res
    }
}