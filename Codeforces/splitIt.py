from curses import beep
from re import A


t = int(input())
while(t):
    n, k = map(int, input().split())
    s = str(input())
    t -= 1
    flag = False
    for i in range(k):
        if(s[i] != s[n-i-1]):
            flag = True
            break
    if(flag or k == n/2):
        print("NO")
    else:
        print("YES")

# take this example
# k = 3
# k+1 = 4
# your substring would be
# "a" "b" "c" "neiorfnvjbtvrgjhinv"
# a1   a2  a3  a4 
# abcneiorfnvjbtvrgjhinvcba

# s = a1 + a2 + a3 + a4 + R(a3) + R(a2) + R(a1)