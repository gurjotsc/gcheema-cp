//Handling Strings
    //str1.append(str2) - This concats two strings together. This only works when combining two strings not two chars
        string one = "one";
        string two = "two";
        one.append(two);
        //one is "onetwo"
        one += two;
        //one is also "onetwo"
        //*Note you can't cast a char to string i.e.
        char temp = 'A'; str1.append((string)temp); //won't work
    //To append a char use += i.e:
    char temp = 'A'; str1 += temp;
    //When looking at the last element of a string, you actually store the string sizes as memory so subtracting more than s.size() is invalid and will cause addressing issues
    string s = "temp";
    s.size() - 1 = 3
    s.size() - 2 = 2
    s.size() - 3 = 1
    s.size() - 4 = 0
    s.size() - 5 = ERROR //this will give you an error because you can't use .size() to index out of a string
    s.size() - (-1) = //google this because idk (online compiler is ok with it but leetcode says it is wrong)
    //string.find()
    //returns true if the string exists as a contiguous substring in str
        //string::npos is something to memorize, like map.find(i) == map.end() or something
            //further explanation: it is a static unsigned int delcared as -1 (because that is the highest unsigned
            //size_t type). size_t is defined in certain libraries
    string str = "geeksforgeeks a computer science";
    str.find("geeks") != string::npos // returns true
    str.find("geeeks") != string::npos // returns false
    //returns a substring in the format [first, last)
        //depending on where you are running your code this could be in the format [forst, last]. Leetcode uses the [first, last) format
    string s = "abcde";
    int i = 1, j = 3;
    s.substr(i, j); // returns "bc"


//Note negative%positve is a positive
//i.e
-11%7 == 4

//begin and end iterators
//iterators are like pointers that point to elements
vec.begin(); vec.end(); //use .begin() and .end() for vectors/strings
begin(s); end(s); //use begin() and end() for vectors/strings
*vec.begin() / *begin(s) //both return the first element by dereferencing the iterator (which is a pointer)
//**Important, vec.end()/end(s) return an iterator pointing the the memory AFTER the array
//When calling a function that uses iterators, you can think of the function as calling [vec.begin(), vec.end()) inclusive - exclusive
//thus if you want to call say reverse(vec.begin(), vec.begin() + 4) it will call it on index [0, 3]
    for(auto it = vec.begin(); it < vec.end(); ++it) {
        cout << *it; //prints out all elements in vec
    }
    for(auto it = vec.begin() + 1; it <= vec.end(); ++it) {
        cout << *prev(it); //also prints out all the elements in vec
    }
    for(auto it = vec.end()-1; it >= vec.begin(); --it) {
        cout << *it; //prints out all elements in vec backwards
    }
    //see below for how to iterate through a map

//delcare multiple variables in one line
    int a = 1, b = 2, c = 3;

//set is a BST that orderes data O(logn)
//unordered_set is a hash O(1)
//multiset is a set that allows duplicates

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

//.erase needs an iterator
int i = someNumber;
unordered_map<int, int> m;
unordered_set<int> s;
m.erase(m.find(i));
s.erase(s.find(i));

//Removes from the vector either a single element (position) or a range of elements ([first,last)).
vector<int> v = {1,2,3,4,5};
v.erase(v.begin()+1, v.begin()+3) // v is {1, 4, 5}
v.erase(v.begin()+1) //v is {1,3,4,5}
v.erase(v.begin()+1, v.end()-1); // v is {1, 5}
v.erase(v.begin()+1, v.end()); // v is {1} //note v.end() is the element after "5" but since the second parameter is exclusive, it erases till the last index

string s = "abcde";
s.erase(1, 3); // s is "ae" READ THIS AS STARTING AT INDEX 1 ERASE 3 ELEMENTS ** YOU CAN"T DIRETLY INDEX ON vector.erase()
s.erase(s.begin() + 0, s.begin() + 4); // s is "e", *note this is still the same [first,last) syntax as vector.erase()


//vector sizing and resizing
vector<vector<int>> vec(n , vector<int> (m, 0)); //declares a nxm grid of 0's
vector<vector<int>> vec(n , vector<int> (m)); //also declares a nxm grid of 0's

vector<int> v = {1,2,3,4,5};
v.resize(4) //v is {1,2,3,4}

vector<int> v = {1,2,3,4,5};
v.resize(8) //v is {1,2,3,4,5,0,0,0}

vector<int> v = {1,2,3,4,5};
v.resize(8, 9) //v is {1,2,3,4,5,9,9,9}

//vector min and max
    vector<int> nums = {1, 2, 3, 7, 5, 1};
    int a = *min_element(begin(nums), end(nums)); //a is 1
    int b = *max_element(begin(nums), end(nums)); //b is 7


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

//Structure binding
    //is super cool...flex on the interviewer
    //Allows you to delcare multiple variables at once witha tuple
        int arr[3] = { 1, 2, 3 };
        auto[x, y, z] = arr;
        //x is 1, y is 2, and z is 3
//ternary operator
    //variable = if (experession == true) ? then value 1 : else value 2
        int x = 1; int y = 2;
        int temp = (x + y == 3) ? 5 : 7; //temp becomes 5
        int temp2 = (x + y == 4) ? 5 : 7; //temp2 becomes 7
    //can use with push_back() as well
        vector<int> temp;
        temp.push_back((x + y == 3) ? 5 : 7) //5 gets pushed back
        temp.push_back((x + y == 4) ? 5 : 7) //7 gets pushed back
//How to traverse an unordered_map or regular map
    int arr[] = { 1, 1, 2, 1, 1, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> m1;
    map<int, int> m2;
    for (int i = 0; i < n; i++)
        m1[arr[i]]++; //stores freq of arr
        m2[arr[i]]++; //stores freq of arr ordered by value
    cout << "Element Frequency" << endl;
     for (auto i : m1)
        cout << i.first << "    " << i.second
             << endl;
     for (auto j : m2)
        cout << j.first << "    " << j.second
             << endl;

return 0;

//How to traverse an unordered or ordered map using iterator (it)
    //key thing to note here is that it is like a vector, m.begin() points to the first element and m.end() is one past the last element
    //**NOTE unlike a vector you must use prev() instead of m.end() - 1, since a tree is stored in a tree im guessin, the elemnts in memory are not one after another, instead
    //the tree is pointing to elements
        //because of this, idk why ++it and --it work

    //**NOTE unlike a vector, you can't use it < m.end() due to the aformentioned reason
    for (auto it = m.begin(); it != m.end(); ++it)
           cout << it->first << "	 " << it->second
               << endl;
    //also works got unordered_map
    for(auto &p : m) { //no need for & but it will run slower if you use it because you then need to copy
        cout << p.first << p.second
        << endl;
    }
    //this iterates backward
    for (auto it = prev(m.end()); it != prev(m.begin()); --it)
           cout << it->first << "	 " << it->second
               << endl;

//map vs unordered_map vs multimap
//map
    //map is a self-balancing BST so O(logn) lookups and O(logn) insertion/deletion
    //Inserts the elements in order for you
    //Useful if you need to print elements in order
//unordered_map
    //unordered_map uses a hash table so average case O(1) lookups and insertion/deletion
        //Wosrt case is O(n) lookups and insertion/deletion
    //unordered (obviously)
//multimap
    //just a map but can store multiple elements
    //This means it is sorted and has the same runtimes
    //If two keys are the same, they are NOT sorted by value, rather in the order they were inserted
        //in our case (6,40) is first then (6,10), then (6,30)
    //Need to insert pairs unlike other maps
    multimap <int, int> m
    m.insert(pair <int, int> (1, 40))
    m.insert(pair <int, int> (2, 40))
    m.insert(pair <int, int> (6, 40))
    m.insert(pair <int, int> (6, 10))
    m.insert(pair <int, int> (6, 30))
//Bounds for SORTED arrays
    // lower_bound (Iterator first, Iterator last, const val)
    // upper_bound (Iterator first, Iterator last, const val)
    // lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value NOT less than ‘val’.
    // upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
    vector<int> v = {5, 6, 7, 7, 6, 5, 5, 6};
    sort(v.begin(), v.end()); //5 5 5 6 6 6 7 7
    lower_bound(v.begin(), v.end(), 6) - v.begin() //returns index of first 6 at idx 3 since its the first value NOT less than val (6)
    upper_bound(v.begin(), v.end(), 6) - v.begin() //returns index of first 7 at idx 6 since its the first value greater than val (6)
    //- v.begin() is because the bounds return iterators, not ints

//Zero Initialization
    int array[5]{ 7, 4, 5 }; // only initialize first 3 elements
    //array = {7, 4, 5, 0, 0}
    int array[5]{ }; //array = {0, 0, 0, 0, 0}
    //Omitted Length
    //The two lines below are the same
    int array[5]{ 0, 1, 2, 3, 4 }; // explicitly define the length of the array
    int array[]{ 0, 1, 2, 3, 4 }; // let the initializer list set length of the array
//In line set creation
    //given string s, stores all characters once in between an index i and n-1
    string temp = "temp string";
    int i = 1;
    int j = 6;
    unordered_set<char> s (begin(temp) + i, begin(temp) + j);
    //in the format [first, last)
    //see if this expands to maps?

//Shift Operators
/*
From gfg
Eg: N<<i (N: first operand, i: second operand)
Takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
Or in other words left shifting an integer “x” with an integer “y” denoted as ‘(x<<y)’ is equivalent to multiplying x with 2^y (2 raised to power y).

Eg: N>>i (N: first operand, i: second operand)

Takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
In other words right shifting an integer “x” with an integer “y” denoted as ‘(x>>y)‘ is equivalent to dividing x with 2^y.

*/
__builtin_popcountll //counts how many ones there are in O(1) in binary


//Comparators
//C++ SHOULD RETURN FALSE ON EQUAL ELEMENTS
bool comp1(pair<int, int> a, pair<int, int> b){
	return (a.second < b.second);
}
//this will sort a vector of pairs by the second value, lowest to greatest NO NEED TO PASS IN vector<pair<int, int>>
//its saying IF a.second is less than another b.second, THEN a should come BEFORE b 
//note pairs automatically sort by .first if a comparator isn't specified
bool comp2(vector<int> a, vector<int> b){
	return (a[1] < b[1]);
}
//this will sort a vector of vector<int> of size 2 by the second value, lowest to greatest
//its saying IF a[1] is less than another b[1], THEN a should come BEFORE b 


//Floor and Ceil take in doubles as parameters
//accurate Floor (used to floor both positive and negative quotients because c++ ceils integer division on negatives) (i.e -10/3 = -3 not -4)
ll accFloor(ll num, ll div) {
    ll val = num/div;
    if(val*div > num) --val;
    return val;
}













    

    

    // vector<int> v(n+1, 0);
    // for(int i = 1; i <= n; ++i) v[i] = a[i]+v[i-1];
    
    
    
    //   //     0 1 2  3  4  5  6  7  8  9  10
    // //pre = {0 3 10 22 37 24 33 23 -7 33 43}
    // a = {3 7 12 15 -13 9 -10 -30 40 10}
    //                       i
    // mn = 0
    // curr = 23
    // res = 37
    // int res = INT_MIN;
    // int mn = 0, curr = 0;
    // for(int i = 0; i < n; ++i) {
    //     if(curr < mn) mn = curr;
    //     curr += a[i];
    //     res = max(res, curr-mn);
    // }
    // return res;
    
    
    // for(auto& q :  queries) {
    //     // int l = q.first;
    //     // int r = q.second;
    //     auto [l, r] = q; //q = {1, 3}
    //     int res = v[r] - v[l-1];
    //     cout << res << " ";
    // }
    // 1 3 = 22
    // 2 5 = 37
    // 3 5 = 30
    // 3 7 = 49
    // 6 8 = 39





























