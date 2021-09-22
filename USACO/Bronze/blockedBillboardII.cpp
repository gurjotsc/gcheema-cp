#include <bits/stdc++.h>
using namespace std;

struct rect {
    int x1, y1, x2, y2;
};

bool covered(int x, int y, rect a) {
    return x >= a.x1 && y >= a.y1 && x <= a.x2 && y <= a.y2; //return whether the corner is covered by bessie's billboard
    //Need to check to make sure the corner is in between the x side and y side of bessie's billboard
}

int area(rect a) {
    return (a.x2 - a.x1) * (a.y2 - a.y1); //area of rectangle
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    rect a; //larry
    rect b; //bessie
    int coveredCornerCount = 0; //Keep track of how many corners are covered

    //input
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    //check to see how many coners are covered by bessie's billboard
    if(covered(a.x1, a.y1, b)) ++coveredCornerCount;
    if(covered(a.x1, a.y2, b)) ++coveredCornerCount;
    if(covered(a.x2, a.y1, b)) ++coveredCornerCount;
    if(covered(a.x2, a.y2, b)) ++coveredCornerCount;

    //If nothing is covered you need to put tarp over the whole thing
    //If one corner is covered you still print the area because the tarp is rectangular and you need to cover the whole thing
    if(coveredCornerCount < 2) cout << area(a);
    //If bessie's billboard covers everything then you can cout 0
    else if (coveredCornerCount == 4) cout << 0;
    //Else find the area of larry's billboard and subtract how much of Bessie's overlaps
    else {
        rect intersect;
        intersect.x1 = max(a.x1, b.x1);
        intersect.x2 = min(a.x2, b.x2);
        intersect.y1 = max(a.y1, b.y1);
        intersect.y2 = min(a.y2, b.y2);
        cout << area(a) - area(intersect);

    }

    return 0;
}
