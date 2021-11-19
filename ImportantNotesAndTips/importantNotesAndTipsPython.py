#string slicing
    a = "Sammy Shark!"
        a[beginning:end:step]
        a[5:10] = " Shar"
        a[5:10:2] = " hr"
        a[:-1] = "Sammy Shark"
        a[::-1] = "!krahS ymmaS"
        a[-4:-1] = "ark"
#string.split(seperator, maxSplits)
    #automatically resturn list of string split by whitespace
    #doesn't include seperator in list
    a = "Sammy Shark!"
    b = "Sammy Shark, Peter Porcupine, Charlie Camel!"
    a.split() = ["Sammy", "Shark"]
    b.split(",") = ["Sammy Shark", "Peter Porcupine", "Charlie Camel!"]
    b.split(",", 1) = ["Sammy Shark", "Peter Porcupine, Charlie Camel!""]
#declare multiple variables in a line
    a, b = 100, 200
        #a is 100 and b is 200
    a = b = 100
        #a and b are both 100
# 200
#map()
    #all map does is take a function and pass the second parameter into it.
        def addition(n):
        return n + n

        # We double all numbers using map()
        numbers = (1, 2, 3, 4)
        result = map(addition, numbers)
        print(list(result))
        #prints [2, 4, 6, 8]
    #when parsing you need to use the following or else you are gonna get the char/string of the input
    map(int, input.split()) #all this does is store the input.split() as an int
#list()
    #converts to a list
#* asterik operator in python
    #known as unpacking a list
    #passes a variable number of arguments into a function indvidually
    num_list = [1,2,3,4,5]
    def num_sum(num1,num2,num3,num4,num5):
        return num1 + num2 + num3 + num4 + num5
    num_sum(num_list[0], num_list[1], num_list[2], num_list[3], num_list[4]) #returns 15
    num_sum(*num_list) #returns 15 by unpacking all the elements in num_list
#ternary operators in python
    x = 5
    a = 3
    b = 2
    x = a if (a>b) else b #returns a if a is larger than b, else b. x = max(a,b), x would be assigned 3
    x += a if (a>b) else b #returns x += a if a is larger than b, else x += b. x += max(a,b). x would become 8
