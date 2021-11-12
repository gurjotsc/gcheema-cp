N = int(input())
p = list(map(int, input().split()))

ans = 0

for i in range(len(p)):
    for j in range(i+1, len(p)+1):
        avg = sum(p[i:j]) / (j-i)
        for x in p[i:j]:
            if(x == avg):
                ans += 1
                break
print(ans)
