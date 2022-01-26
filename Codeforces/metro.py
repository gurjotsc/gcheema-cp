n, s = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if(not a[0]):
    print("NO")
elif(not a[s-1] and not b[s-1]):
    print("NO")
elif(a[s-1]):
    print("YES")
elif(not sum(a[s:n])):
    print("NO")
else:
    flag = False
    for i in range(s, n):
        if(a[i] and b[i]):
            flag = True
            break
    if(not flag):
        print("NO")
    else:
        if(b[s-1]):
            print("YES")
        else:
            print("NO")
        

