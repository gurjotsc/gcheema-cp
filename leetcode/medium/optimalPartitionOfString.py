class Solution:
    def partitionString(self, s: str) -> int:
        st = set()
        res = 0
        for i in s:
            res += (i in st)
            if i in st:
                st.clear()
            st.add(i)
        return res+1