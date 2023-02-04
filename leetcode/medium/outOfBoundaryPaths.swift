class Solution {
    func findPaths(_ m: Int, _ n: Int, _ maxMove: Int, _ startRow: Int, _ startColumn: Int) -> Int {
        if maxMove == 0 {return 0}
        var dp = Array(repeating: Array(repeating: 0, count: n), count: m)
        let mod = Int(1e9)+7
        dp[startRow][startColumn] = 1
        var res = 0
        for move in 1...maxMove {
            var temp = Array(repeating: Array(repeating: 0, count: n), count: m)
            for i in 0...m-1 {
                for j in 0...n-1 {
                    print(i, j)
                    if i == m-1 {res = (res+dp[i][j])%mod}
                    if j == n-1 {res = (res+dp[i][j])%mod}
                    if i == 0 {res = (res+dp[i][j])%mod}
                    if j == 0 {res = (res+dp[i][j])%mod}

                    temp[i][j] = ((i > 0 ? dp[i-1][j] : 0) + (i < m-1 ? dp[i+1][j] : 0)) % mod + 
                                 ((j > 0 ? dp[i][j-1] : 0) + (j < n-1 ? dp[i][j+1] : 0)) % mod
                }
            }
            dp = temp
        }
        return res
    }
}