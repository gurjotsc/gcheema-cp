class Solution {
    func validateBinaryTreeNodes(_ n: Int, _ leftChild: [Int], _ rightChild: [Int]) -> Bool {
        var visited: Set<Int> = []
        var cntEdges = 0
        var root: Int?
        var nums: Set<Int> = []
        let l = Set(leftChild)
        let r = Set(rightChild)

        func dfs(_ r: Int) -> Bool {
            if visited.contains(r) {return false}
            visited.insert(r)
            if leftChild[r] != -1 && rightChild[r] != -1 {
                cntEdges += 2
                return dfs(leftChild[r]) && dfs(rightChild[r])
            }
            else if leftChild[r] != -1 {
                cntEdges += 1
                return dfs(leftChild[r])
            }
            else if rightChild[r] != -1 {
                cntEdges += 1
                return dfs(rightChild[r])
            }
            return true
        }

        for i in 0...n-1 {
            if leftChild[i] != -1 {
                nums.insert(i)
                nums.insert(leftChild[i])
            }
            if rightChild[i] != -1 {
                nums.insert(i)
                nums.insert(rightChild[i])
            }
        }

        for i in 0...n {
            if !nums.contains(i) {continue}
            if l.contains(i) {continue}
            else if r.contains(i) {continue}
            else {
                root = i
                break
            }
        }

        if let r = root {
            return dfs(r) && (cntEdges == n-1)
        }
        return n == 1
    }
}