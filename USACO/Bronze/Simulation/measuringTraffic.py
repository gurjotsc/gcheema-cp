import sys
sys.stdin = open("traffic.in", 'r')
sys.stdout = open("traffic.out", 'w')



N = int(input())
#need to initialize these to sys.minsize and sys.maxsize equivalents so that our first none readings be taken in as inputs
prior = [-999999999, 999999999]
after = [-999999999, 999999999]
sensors = [input().split() for _ in range(N)]

#iterating forwards
for s in sensors:
    s[1] = int(s[1])
    s[2] = int(s[2])
    if(s[0] == "on"):
        #if a car gets on then we can update the lower bound by s[1] (since this stores the least possible)
        #if a car gets on then we can update the upper bound by s[2] (since this stores the highest possible)
        after[0] += s[1]
        after[1] += s[2]
    elif(s[0] == "off"):
        #remove a car when it gets off, or make it 0 if it detects more cars getting off
        #we want the lower bound to decrease by the higher amount because we are trying to return the most specific ranges
        #in other words, the lower bound needs to decrease by s[2] since s[2] is the larger value and our range needs to account for all possible values
        after[0] = after[0] - s[2] if (after[0] - s[2] > 0) else 0
        after[1] -= s[1]
    elif(s[0] == "none"):
        #for a range to be specifc, it must "fit inside" all ranges
        #the only way we can achieve this is if we take the max of the lowest detected ranges
        #and the min of the highest detected ranges
        after[0] = max(s[1], after[0])
        after[1] = min(s[2], after[1])

#iterating backwards
for s in sensors[::-1]:
    s[1] = int(s[1])
    s[2] = int(s[2])
    if(s[0] == "none"):
        #for a range to be specifc, it must "fit inside" all ranges
        #the only way we can achieve this is if we take the max of the lowest detected ranges
        #and the min of the highest detected ranges
        prior[0] = max(s[1], prior[0])
        prior[1] = min(s[2], prior[1])
    elif(s[0] == "off"):
        #you know that there had to have been at least (prior[0 - 1] (initially 0) += how many got off) before the ramp
        prior[0] += s[1]
        prior[1] += s[2]
    elif(s[0] == "on"):
        #you know that there had s[1-2] less cars before they got on
        prior[0] = prior[0] - s[2] if (prior[0] - s[2] > 0) else 0
        prior[1] -= s[1]

print(*prior)
print(*after)
