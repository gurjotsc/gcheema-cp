def additionWithConversion(s1, s2):
    n1 = len(s1) - 1
    num1 = 0
    for i in range(len(s1)):
        num1 += (pow(2, n1 - i) * int(s1[i]))
    n2 = len(s2) - 1
    num2 = 0
    for j in range(len(s2)):
        num2 += (pow(2, n2 - j) * int(s2[j]))
    return bin(num1 + num2)[2:]

s1 = "100"
s2 = "1"

print(additionWithConversion(s1, s2))
