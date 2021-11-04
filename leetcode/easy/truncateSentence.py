class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        #join a list of k ([:k]) words from s.split() with " "
        #s.split() creates a list seperatred by whitespace (" ")
        return " ".join(s.split()[:k])

        # count = 0
            #count how many words you have encountered aka count how many spaces
            #break once you see k spaces
        # for i in range(len(s)):
        #     if (s[i] == ' '): count += 1
        #     if (count == k): break
            #if its the whole sentece, then return everything (hence the i+1, since i is 0-                    indexed)
            #else, since i is 0-indexed, return s[0:i] which won't include the whitespace
        # return s[0:i+1] if i == len(s) - 1 else s[0:i]
            
