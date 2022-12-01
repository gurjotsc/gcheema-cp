class Solution:
    def greatestLetter(self, s: str) -> str:
        st = set()
        res = ''
        for i in s:
            if i.islower():
                if i.upper() in st:
                    res = max(res, i.upper())
            elif i.lower() in st:
                res = max(res, i)
            st.add(i)
        return res