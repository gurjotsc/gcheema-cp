def correctCapitalization(s):
    if(s.islower()): return True
    elif(s.isupper()): return True
    elif(s[0].islower()): return False
    else:
        for ch in range(2, len(s)):
            if(s[ch].isupper()): return False
        return True;


s = "coding"
print(correctCapitalization(s))
