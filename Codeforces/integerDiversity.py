t = int(input())
while(t):
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    res = set()
    for i in a:
        if(i in res):
            if(abs(i) not in res):
                res.add(abs(i))
            elif(i*-1 not in res):
                res.add(i*-1)
        else:
            res.add(i)
    print(len(res))
