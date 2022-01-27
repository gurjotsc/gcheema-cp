t = int(input())
while(t):
    n = int(input())
    res = [None] * n
    for i in range(n):
        res[i] = i+2
    print(*res)
    t -= 1