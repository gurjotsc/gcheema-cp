class Solution {
    func champagneTower(_ poured: Int, _ query_row: Int, _ query_glass: Int) -> Double {
        var arr = Array(repeating: Array(repeating: 0.0, count: 102), count: 102)
        arr[0][0] = Double(poured)
        for r in 0...query_row{
            for c in 0...query_glass{
                var flow = (arr[r][c]-1.0)/2.0
                guard flow > 0 else {continue}
                arr[r+1][c] += flow
                arr[r+1][c+1] += flow
            }
        }
        return min(1, arr[query_row][query_glass])
    }
}