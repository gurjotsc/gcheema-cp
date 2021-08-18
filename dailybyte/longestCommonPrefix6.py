def longestCommonPrefix(s):
    check = 0
    for i in range(len(s)):
        if(len(s[i]) > len(s[check])): check = i
    for j in range(len(s[check])):
        for x in s:
            same = True
            if(len(x) < len(s[check]) - j or s[check][:len(s[check]) - j] != x[:len(s[check]) - j]):
                same = False
                break
        if(same): return s[check][:len(s[check]) - j]
    return ""

s = ["spot", "spotty", "spotted"]
print(longestCommonPrefix(s))
