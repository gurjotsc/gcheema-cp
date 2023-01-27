class Solution {
    func findCenter(_ edges: [[Int]]) -> Int {
        if edges[0].contains(edges[1][0]) {return edges[1][0]}
        return edges[1][1]
    }
}