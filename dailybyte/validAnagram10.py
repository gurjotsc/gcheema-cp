def isValidAnagram(s1, s2):
    return sorted(s1) == sorted(s2)


s1 = "gurjot"
s2 = "tojrugg"
print(isValidAnagram(s1, s2))
