t = int(input())
while(t):
    t-=1
    n = int(input())
    s = str(input())
    res = ""
    for i in s:
        if(i == 'D'):
            res += 'U'
        elif(i == 'U'):
            res += 'D'
        else:
            res += i
    print(res)