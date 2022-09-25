class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        st = set(('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'))
        return len(list(filter(lambda x : x in st, s[:len(s)//2]))) == len(list(filter(lambda x : x in st, s[len(s)//2:len(s)])))