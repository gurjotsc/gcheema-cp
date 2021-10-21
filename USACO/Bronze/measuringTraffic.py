import sys

sys.stdin = open("traffic.in", 'r')
sys.stdout = open("traffic.out", 'w')

N = int(input())
in = [0, 0]
out = [0, 0]
for i in range(N):
    sense = list(input().split())
    sense[1] = int(sense[1])
    sense[2] = int(sense[2])
    if(i == 0):
        in[]
