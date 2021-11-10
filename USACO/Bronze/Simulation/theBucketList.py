import sys

sys.stdin = open("blist.in", "r")
sys.stdout = open("blist.out", "w")

N = int(input())
sum = [0] * 1001 #holds how many buckets are used only at the start and end indexes (1001 so indexing is easier, 0 won't ever be
                 #touched)

for i in range(N):
    cow = list(map(int, input().split()))
    sum[cow[0]] += cow[2] #increment by the buckets and when the cow starts
    sum[cow[1]] -= cow[2] ##decrement when the cow is done

cur = 0
ans = 0
for i in sum:
    cur += i #increase when a cow starts milking and decrease when it is done
    ans = max(ans, cur) #store the max

print(ans)
