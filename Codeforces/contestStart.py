import sys

k = int(input())
while(k):
    k -= 1
    n,x,t = map(int, input().split())
    res = 0
    howManyRunnersAtOneTime = min(n, t//x)
    res = howManyRunnersAtOneTime*(howManyRunnersAtOneTime-1)//2
    res += howManyRunnersAtOneTime*(n - howManyRunnersAtOneTime)
    print(res) 