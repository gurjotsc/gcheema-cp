t = int(input())
while(t):
    s = str(input())
    if(len(s) % 2):
        print("NO")
    elif(s[0:len(s)//2] == s[len(s)//2:len(s)]):
        print("YES")
    else:
        print("NO")
    t -= 1