class Solution {
    func fairCandySwap(_ a: [Int], _ b: [Int]) -> [Int] {
        let sumA = a.reduce(0,+)
        let sumB = b.reduce(0,+)

        let diff = (sumB-sumA)/2 //no need to cast to double, since questions states there is a valid answer
        let sb = Set(b)

        for i in a {
            guard sb.contains(i+diff) else {continue} //alice gives i and recieves i+diff
            return [i, i+diff]
        }

        return [-1,-1]
    }
}