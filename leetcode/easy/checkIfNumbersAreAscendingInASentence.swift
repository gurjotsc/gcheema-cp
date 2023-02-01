sclass Solution {
    func areNumbersAscending(_ s: String) -> Bool {
        let a = s.split(separator: " ").compactMap{Int($0)}
        var prev = 0
        for i in a {
            guard i > prev else {return false}
            prev = i
        }
        return true
    }
}