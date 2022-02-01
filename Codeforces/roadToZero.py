t = int(input())
while(t):
    x, y = map(int, input().split())
    a, b = map(int, input().split())
    t -= 1
    if(x == y):
        print(min(a*x*2, b*x))
    else:
        case1 = a*(x+y) #case 1 indivisuall bring each down
        case2 = a*(max(x,y) - min(x,y)) + b*(min(x,y)) #bring down the bigger one then decrease both together
        print(min(case1, case2))