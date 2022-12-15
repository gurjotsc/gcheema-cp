class Solution:
    def __init__(self):
        self.res = [0]*51
        self.res[1] = 5
        a = e = i = o = u = 1
        def increment():
            nonlocal a,e,i,o,u
            a = a+e+i+o+u
            e = e+i+o+u
            i = i+o+u
            o = o+u
            #we don't add u += u because theres always only one string with just u's
        for j in range(2,51): #use j as an iterator because i is a vowel
            increment()
            self.res[j] = a+e+i+o+u
        
    def countVowelStrings(self, n: int) -> int:
        return self.res[n]