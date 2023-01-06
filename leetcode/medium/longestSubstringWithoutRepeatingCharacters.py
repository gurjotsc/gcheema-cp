class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        if not n or n == 1:
            return n
        st = set()
        l = r = 0
        res = 0
        for i in range(n):
            if s[i] in st:
                res = max(r-l+1, res)
                l = l+s[l:i].index(s[i])+1
                st = set(s[l:i])
            st.add(s[i])
            r = i
        return max(res, r-l+1)