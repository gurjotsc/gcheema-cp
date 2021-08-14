def checkPalindrome(s):
    s = s.lower()

    for ch in s:
        if not ch.isalpha():
            s = s.replace(ch, "")

    r = s[::-1]

    return r == s
