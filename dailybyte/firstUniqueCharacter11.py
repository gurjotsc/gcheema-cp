def firstUniqueCharacter(s):
    for i in range(len(s)):
        if(not i):
            if(s[i + 1:].find(s[i]) >= 0): continue
        elif(i == len(s) - 1):
            if(s[:i - 1].find(s[i]) >= 0): return -1
        else:
            if(s[i + 1:].find(s[i]) >= 0 or s[:i].find(s[i]) >= 0): continue
        return i

s = "developer"
print(firstUniqueCharacter(s))
