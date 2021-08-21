def countJewels(j, s):
    count = 0
    for i in j:
        while(s.find(i) >= 0):
            count += 1
            s = s[:s.find(i)] + s[s.find(i) + 1:]
    return count

j = "Af"
s = "AaaddfFf"
print(countJewels(j,s))
