import sys

sys.stdin = open("lostcow.in", 'r')
sys.stdout = open("lostcow.out", 'w')

x, y = map(int, input().split())

it = 1
distance = 0
if(x != y):
    while(1):
        distance += (it - 1) + it
        temp = x + it
        if(y <= temp and y >= x):
            break
        else:
            it += 1
        distance += (it - 1) + it
        temp = x - it
        if(y >= temp and y <= x):
            break
        else:
            it += 1
print(distance)
