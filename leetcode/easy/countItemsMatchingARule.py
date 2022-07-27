class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        res = 0
        prev = 0
        for i in items:
            res += (ruleKey == "type" and ruleValue == i[0])
            res += (ruleKey == "color" and ruleValue == i[1])
            res += (ruleKey == "name" and ruleValue == i[2])
            if res - prev >= 2: res = prev
            prev = res
        return res