#string slicing
    #a = "Sammy Shark!"
        a[beginning:middle:step]
        a[5:10] = " Shar"
        a[5:10:2] = " hr"
        a[:-1] = "Sammy Shark"
        a[::-1] = "!krahS ymmaS"
        a[-4:-1] = "ark"
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
    map(int, input.split()) #all this does is store the input.split as an int
#list()
    #converts to a list
