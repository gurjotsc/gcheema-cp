class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        S = s.replace("-", "").upper() #Only uppercase characters
        count = len(S)

        first = count % k #the remainder aka the size of the first group
        ans = ""
        if(first): ans = S[:first] + "-"
        #iterate through the string starting from first and going to count, steping k every time and adding it to ans
        for i in range(first, count, k):
            ans += (S[i:i+k] + "-")
        return ans[:-1] #you don't want the last "-", hence the [:-1]
