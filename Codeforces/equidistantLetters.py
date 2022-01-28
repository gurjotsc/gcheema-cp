t = int(input())
while(t):
    s = str(input())
    print(*sorted(s), sep='')
    t-=1