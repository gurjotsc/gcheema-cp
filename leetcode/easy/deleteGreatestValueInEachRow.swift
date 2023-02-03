class Solution {
    func deleteGreatestValue(_ grid: [[Int]]) -> Int {
        var res = 0
        var g = grid
        let m = g.count, n = g[0].count
        for i in 0...m-1 {g[i].sort()}
        for j in 0...n-1{
            var mx = -1
            for i in 0...m-1 {
                mx = max(mx, g[i][j])
            }
            res += mx
        }
        return res
        
    }
}