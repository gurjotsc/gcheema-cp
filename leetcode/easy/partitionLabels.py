class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans = []
        #enumerate starts from 0
        #This creates a dict for each letter and stores its last index
        rightMost = {c:i for i,c in enumerate(s)}
        #iterators to keep track of our anchor (start of the string) and see if our current              index is the rightmost index
        right=left=0
        #look through enumerate(s) until you find a rightmost[letter]
        for idx, letter in enumerate(s):
            #right is going to store the index of whatever letter is the rightmost in your                    string
            #As we iterate through a string, this will update everytime we encounter a letter                that occurs farther in the string
            right = max(right, rightMost[letter])
            #once we reach that letter that means we haven't encountered a letter that appears                later
            #the next iteration will start at the next letter
            if idx == right:
                #ans.append(len(s[left:right+1])) - intuition but we can just use our indexes
                ans.append(right-left+1) #append the size
                left = right + 1 #update for the next string
        return ans
            
