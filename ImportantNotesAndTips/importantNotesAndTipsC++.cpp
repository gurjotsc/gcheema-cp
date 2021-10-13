//Handling Strings
    //str1.append(str2) - This concats two strings together. This only works when combining two strings not two chars
        //*Note you can't cast a char to string i.e.
        char temp = 'A'; str1.append((string)temp); //won't work
    //To append a char use += i.e:
    char temp = 'A'; str1 += temp;

//Tuples
    //Use get<iterator of index in tuple>(tuple)
        //i.e.
        tuple<int, int, int> p; p = {1,2,3}; cout << get<0>(p); // This couts 1
        //i.e.
        tuple<int, int, int> p; p = {1,2,3}; get<0>(p) = 4; // This changes the 1 to a 4

//Variable Type Notes
    //Converting to (int) before a number always rounds down i.e:
        double x = 3.99999;
        int y = (int)x;
        y is equal to 3

//Trees
    //DON"T USE VAL WHEN CHECKING NULL. NULL IS A POINTER THAT POINTS TO NOTHING IN MEMORY, NOT A VALUE

//Binary Search
    //set mid
    int mid = lo + ((hi - lo) / 2);
//use {} for ifs, fors, whiles, and DECLERATIONS
    vector<int> temp = {1, 2, 3, 3, 2, 1};
    pair<int, int> temp = {1,0};

//declare two-d vector with vector on the inside
    vector<vector<int>> temp(m, (vector<int> (n, 20)));
