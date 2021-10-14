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

//queue<> uses push, pop, front, back
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(1);
    q.push(7);
    // q becomes 3, 4, 1, 7
    //think of 3 as "came first so is in front of line while 7 is in the back cuz they came last"
    q.front(); // 3
    q.back() // 7
    q.pop() //removes 3
    //*Note* you can't pop and equal something at the same time. For instance:
    int temp = q.pop() //DOESN"T WORK
