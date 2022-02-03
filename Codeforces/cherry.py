t = int(input())
while(t):
    t-=1
    n = int(input())
    a = list(map(int, input().split()))
    b = 0
    s = 10e6
    res = 0
    for i in range(1, len(a)):
        res = max(res, a[i] * a[i-1])
    print(res)
