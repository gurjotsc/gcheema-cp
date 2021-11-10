import sys
sys.stdin = open("diamond.in", 'r')
sys.stdout = open("diamond.out", 'w')

N, K = map(int, input().split())
diamonds = [int(input()) for _ in range(N)]
ans = 0
#For each of the diamonds
for i in diamonds:
    count = 0
    largest = i + K
    smallest = i
    #For each of the diamonds look through diamonds again and see which values are <= i
    #the reason we made smallest = i is because as you iterate through diamonds, you will look through each and every value
    #which means you will eventually look at the smallest value
    #for the smallest value, only numbers that are larger than it but less than smllest + K will work
    #since we can do this for the smallest value, you only have to look at larger diamonds than i for the rest of i
    #for instance, say you had a value in dimonds that was the min(diamonds) + 1 and another value that was min(diamonds) + K + 1
    #when i == min(diamonds), the min(diamonds) + K + 1 wouldn't work
    #if i == min(diamonds) + 1 then min(diamonds) + K + 1 would work but you could no longer include min(diamonds)
    #this is why we only treat each i as the smallest and then look through the whole array
    for j in diamonds:
        if(j >= smallest  and j <= largest): count += 1
    ans = max(ans, count)
print(ans)
#youll eventually look through with i = smallest integer
