import sys

sys.stdin = open("lostcow.in", 'r')
sys.stdout = open("lostcow.out", 'w')

x, y = map(int, input().split())

it = 1
distance = 0
curr = x
if(x != y):
    while(1):
        curr += it
        distance += abs(temp - curr)
        if(curr >= y and x < y): break
        else: it *= 2
        temp = curr
        curr -= it
        distance += abs(temp - curr)
        if(curr <= y and x > y): break
        else: it *= 2
print(distance)
