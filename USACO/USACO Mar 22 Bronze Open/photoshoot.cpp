// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const ll inf = 1e18;
// template<typename T>
// std::istream& operator>>(std::istream& input, std::vector<T>& data) {
//      for (auto& item : data) input >> item;
//      return input;
// }
// template <typename T>
// std::ostream& operator <<(std::ostream& output, const std::vector<T>& data) {
//      for (const T& x : data) output << x << " " ;
//      return output;
// }



// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);
    
//     int n; cin >> n;
//     string s; cin >> s;
//     vector<bool> segs;
//     int res = 0;
//     for(int i = 0; i < n; i += 2) {
//         string temp = ""; temp += (s[i] + s[i+1]);
//         if(temp == "GG" || temp == "HH") continue;
//         if(temp == "GH") segs.push_back(false);
//         else segs.push_back(true);
//     }
//     if(!segs.size()) {
//         cout << 0;
//         return 0;
//     }
//     if(segs.size() == 1) {
//         cout << (segs[0]) ? 0 : 1;
//         return 0;
//     }

//     bool prevSeg = segs[0];
//     bool currSeg = segs[1];
//     if(segs[0]) ++res;
//     for(int i = 2; i < segs.size(); ++i) {
//         while( i < segs.size() && currSeg == prevSeg) {
//             prevSeg = currSeg;
//             currSeg = segs[i++];
//         }
//         ++res;
//         prevSeg = currSeg;
//         currSeg = segs[i++];
//     }

//     cout << res;
// }


#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N; cin >> N;
    string S; cin >> S;
    // S += 'G', S += 'G';
    list<int> seg(1, -1);
    for (int x, i=0; i < N; i += 2) {
        x = -1;
        string cur(1, S[i]);
        cur += S[i+1];
        if (cur == "HG") x = 0;
        if (cur == "GH") x = 1;
        if (x == -1) continue;
        if (x != seg.back())
            seg.push_back(x);
    }
    seg.pop_front();
    return seg.size() - (seg.back() == 0);
}

int main() {
    cout << solve() << '\n';
}









// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const ll inf = 1e18;
// template<typename T>
// std::istream& operator>>(std::istream& input, std::vector<T>& data) {
//      for (auto& item : data) input >> item;
//      return input;
// }
// template <typename T>
// std::ostream& operator <<(std::ostream& output, const std::vector<T>& data) {
//      for (const T& x : data) output << x << " " ;
//      return output;
// }



// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);

//     int n; cin >> n;
//     string s; cin >> s;
//     if(s.size()%2) cout << "fail";
//     n = s.size();
//     s = '0' + s;
//     int cntGE = 0, cntGO = 0, cntHE = 0, cntHO = 0;
//     int res = 0;
//     for(int i = 1; i <= n; ++i) {
//         if(s[i] == 'G') {
//             if(!(i%2)) {
//                 ++cntGE;
//                 if(cntGO > cntGE) {
//                     //reverse
//                     ++res;
//                     swap(cntGE, cntGO);
//                     swap(cntHE, cntHO);

//                     // int tempGE = cntGE;
//                     // cntGE = cntGO;
//                     // cntGO = tempGE;

//                     // int tempHE = cntHE;
//                     // cntHE = cntHO;
//                     // cntHO = tempHE;
//                 }
//             }
//             else ++cntGO;
//         }
//         else {
//             if(!(i%2)) ++cntHE;
//             else ++cntHO;
//         }
//     }



//     if(res == 0) {
//         if (cntGO > cntGE) cout << 1;
//         else cout << 0;
//     }
//     else cout << res;

//     return 0;
// }






// // #include <bits/stdc++.h>
// // using namespace std;
// // using ll = long long;
// // const ll inf = 1e18;
// // template<typename T>
// // std::istream& operator>>(std::istream& input, std::vector<T>& data) {
// //      for (auto& item : data) input >> item;
// //      return input;
// // }
// // template <typename T>
// // std::ostream& operator <<(std::ostream& output, const std::vector<T>& data) {
// //      for (const T& x : data) output << x << " " ;
// //      return output;
// // }



// // int main() {
// //     cin.tie(0);
// //     ios::sync_with_stdio(0);

// //     int n; cin >> n;
// //     string s; cin >> s;
// //     s = '0' + s;
// //     int cntGE = 0, cntGO = 0, cntHE = 0, cntHO = 0;
// //     int res = 0;
// //     for(int i = 1; i <= n; ++i) {
// //         if(s[i] == 'G') {
// //             if(!(i%2)) {
// //                 ++cntGE;
// //                 if(cntGO > cntGE) {
// //                     //reverse
// //                     ++res;
// //                     //swap(cntGE, cntGO);
// //                     //swap(cntHE, cntHO);

// //                     int tempGE = cntGE;
// //                     cntGE = cntGO;
// //                     cntGO = tempGE;

// //                     int tempHE = cntHE;
// //                     cntHE = cntHO;
// //                     cntHO = tempHE;
// //                 }
// //             }
// //             else ++cntGO;
// //         }
// //         else {
// //             if(!(i%2)) ++cntHE;
// //             else ++cntHO;
// //         }
// //     }


// //     if(res == 0) {
// //         if (cntGO > cntGE) cout << 1;
// //         else cout << 0;
// //     }
// //     else cout << res;

// //     return 0;
// // }
