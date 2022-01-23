import sys

t = int(input())
while(t):
    n = int(input())
    p = list(map(int, input().split()))
    s = input()
    d = dict()
    ones = []
    zeroes = []
    q = [None] * n
    for i in range(n):
        d[p[i]] = i
    for i in range(n):
        if(s[i] == '0'):
            zeroes.append(p[i])
        else:
            ones.append(p[i])
    ones.sort(reverse=True)
    zeroes.sort(reverse=True)
    p.sort(reverse=True)
    i = 0
    while(i < len(ones)):
        q[d[ones[i]]] = p[i]
        i += 1
    j = 0
    while(j < len(zeroes)):
        q[d[zeroes[j]]] = p[i]
        i += 1
        j += 1
    print(*q)
    t-=1