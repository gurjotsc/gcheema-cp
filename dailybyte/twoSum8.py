def twoSum(arr, k):
    for i in range(len(arr)):
        if(i == len(arr) - 1): return False
        try:
            if(arr[i+1:].index(k - arr[i]) >= 0): return True
        except:
            continue

arr = [4, 2, 6, 5, 2]
print(twoSum(arr, 4))
