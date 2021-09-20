#include <bits/stdc++.h>
using namespace std;

//Store each pasture in a struct
struct rect {
    int x1, y1, x2, y2;
};

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    //Declare each pasture
    rect a;
    rect b;
    //Store the range of x (biggest x - smallest x) in dim1 and repeat the same of dim2
    int dim1;
    int dim2;
    //Holds the square pastures dimension
    int dimSquare;
    //input
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    //Here we want the maximum dimension our square could be for x and y.
    //First we find the largest x position and subtract it by the smallest x position
    //Repeat for y
    dim1 = abs(max(a.x2, b.x2) - min(a.x1, b.x1));
    dim2 = abs(max(a.y2, b.y2) - min(a.y1, b.y1));
    //Our square needs to be at least the dimension of the largest of dim1 and dim2
    dimSquare = max(dim1, dim2);
    cout << dimSquare * dimSquare;
    return 0;
}
