//CodeForces
#include <bits/stdc++.h>
using namespace std;

struct rect {
    int x1, x2, y1, y2;
};
bool checkFit(rect room, rect one, rect two) {
    return one.x1 - room.x1 >= two.x2 || room.x2 - one.x2 >= two.x2 || one.y1 - room.y1 >= two.y2 || room.y2 - one.y2 >= two.y2;
}
int solve() {
    rect room;
    rect one;
    rect two;
    bool canMoveRight = false;
    bool canMoveUp = false;

    room.x1 = 0; room.y1 = 0;
    two.x1 = 0; two.y1 = 0;
    cin >> room.x2 >> room.y2;
    cin >> one.x1 >> one.y1 >> one.x2 >> one.y2;
    cin >> two.x2 >> two.y2;

    if(checkFit(room, one, two)) return 0;
    if(two.x2 == room.x2 && two.y2 == room.y2) return -1; //check if table as big as room 

    rect intersect;
    intersect.x1 = max(one.x1, two.x1);
    intersect.x2 = min(one.x2, two.x2);
    intersect.y1 = max(one.y1, two.y1);
    intersect.y2 = min(one.y2, two.y2);

    if(room.x2 - one.x2 >= intersect.x2 - intersect.x1) canMoveRight = true;
    if(room.y2 - one.y2 >= intersect.y2 - intersect.y1) canMoveUp = true;
    if(canMoveRight && canMoveUp) {
        int right = intersect.x2 - intersect.x1;
        int up = intersect.y2 - intersect.y1;
        return min(right, up);
    }
    else if(canMoveRight) return intersect.x2 - intersect.x1;
    else if(canMoveUp) return intersect.y2 - intersect.y1;

    return -1;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cout << solve() << endl;
    }


    return 0;
}
