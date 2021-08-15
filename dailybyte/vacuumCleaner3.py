def returnToBase(s):
    h = 0
    v = 0
    for ch in s:
        if(ch == "L"):
            h -= 1
        elif(ch == "R"):
            h += 1
        elif(ch == "D"):
            v -= 1
        elif(ch == "U"):
            v += 1
    if(not h and not v):
        return True
    else:
        return False

print(returnToBase("RUULLDRD"))
