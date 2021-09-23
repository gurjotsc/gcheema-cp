//CodeForces Question
#include <bits/stdc++.h>
using namespace std;

struct rect {
    long long x1, y1, x2, y2;
};

long long area(rect a) {
    if((a.x2 - a.x1) <= 0 || (a.y2 - a.y1) <= 0) return 0;
    else return (a.x2 - a.x1) * (a.y2 - a.y1);
}

long long intersect(rect a, rect b) {
    rect temp;

    temp.x1 = max(a.x1, b.x1);
    temp.x2 = min(a.x2, b.x2);
    temp.y1 = max(a.y1, b.y1);
    temp.y2 = min(a.y2, b.y2);

    return area(temp);

}

int main() {
    rect w;
    rect b1;
    rect b2;

    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

    if(!(area(w) - intersect(w, b1) - intersect(w,b2))) cout << "NO";
    else cout << "YES";


    return 0;
}
