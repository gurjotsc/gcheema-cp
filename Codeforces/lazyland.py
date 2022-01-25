n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
x = zip(b, a)
jobs = [0 for i in range(k+1)]
minTimes = [10e10 for i in range(k)]
for i in a:
    jobs[i] += 1
count = 0
for i in jobs:
    if(i):
        count += 1
if(count == k):
    print(0)
else:
    vacant = k - count
    x = sorted(x)
    res = 0
    for i, j in x:
        if(jobs[j] > 1):
            jobs[j] -= 1
            res += i
            vacant -= 1
        if(not vacant):
            break
    print(res if not vacant else 0)