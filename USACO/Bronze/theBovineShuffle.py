import sys

sys.stdin = open("shuffle.in", 'r')
sys.stdout = open("shuffle.out", 'w')

N = int(input())
A = list(map(int, input().split()))
id = list(map(int, input().split()))
past = [0] * N #store the previous iteration of the shuffle

for _ in range(3): #we need to simulate each shuffle going back in time one by one
    for i in range(N): #for each id
        #Here all we're doing is iterating through each element in past and setting it with whatever id was stored at the shuffle
        #index (we minus 1 for indexing)
        #note the shuffles are unique so two indexes won't point to the same index
        past[i] = id[A[i] - 1]
    id = past.copy() #copy id to represent past for the next iteration

for i in id: print(i)
