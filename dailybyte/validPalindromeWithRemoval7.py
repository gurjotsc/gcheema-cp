def isValidPalindromeWithDeletion(s, delete):
    for i in range(len(s)):
        if(i > len(s) - i - 1): return True

        if(s[i] == s[len(s) - i - 1]): continue
        elif (delete): return False
        else:
            s = s[:i] + s[i+1:]
            delete = True
            return isValidPalindromeWithDeletion(s, delete)

    return True

s = "abccab"
delete = False
print(isValidPalindromeWithDeletion(s, delete))
