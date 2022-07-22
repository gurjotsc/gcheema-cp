class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""
        strs.sort(key=len)
        n = len(strs[0])
        i = 0
        flag = False
        while(n):
            res += strs[0][i]
            for j in range(1, len(strs)):
                if res[-1] != strs[j][i]:
                    return res[:-1]
            i += 1
            n -= 1
        return res
                