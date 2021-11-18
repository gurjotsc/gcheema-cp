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

vector<int> v = {1,2,3,4,5};
vector.erase(myvector.begin()+1) //v is {1,3,4,5}

//vector sizing and resizing
vector<vector<int>> vec(n , vector<int> (m, 0)); //declares a nxm grid of 0's
vector<vector<int>> vec(n , vector<int> (m)); //also declares a nxm grid of 0's

vector<int> v = {1,2,3,4,5};
v.resize(4) //v is {1,2,3,4}

vector<int> v = {1,2,3,4,5};
v.resize(8) //v is {1,2,3,4,5,0,0,0}

vector<int> v = {1,2,3,4,5};
v.resize(8, 9) //v is {1,2,3,4,5,9,9,9}

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
//How to traverse an unordered_map
    int arr[] = { 1, 1, 2, 1, 1, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++; //stores freq of arr
    cout << "Element Frequency" << endl;
    for (auto i : m)
        cout << i.first << "    " << i.second
             << endl;
    return 0;
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
