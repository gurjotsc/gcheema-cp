import sys
sys.stdin= open("pails.in", "r")
sys.stdout = open("pails.out", "w")

X, Y, M = map(int, input().split())
ans = 0

#if you can get it by just puring one bucket over and over, just return M
if(not M % X or not M % Y):
    print(M)
    exit()

#since X<Y<M<=1000, check for all possible pour of X, all the possible pours of Y

for pourxTimes in range(1001):
    #once you can no longer fill it up with X * pourxTimes, you can break because there is no way you could fill it up with Y without overflowing either
    if(X * pourxTimes > M): break
    for pouryTimes in range(1001):
        #If the pour doesn't overflow, then update ans if it could be bigger
        if ((X * pourxTimes) + (Y * pouryTimes) <= M): ans = max(ans, (X * pourxTimes) + (Y * pouryTimes))
        else: break #its only gonna get bigger from here, but its already greater than m

print(ans)
