// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<string> s(n);
	unordered_map<char, unordered_set<int>> m;
	for(int i = 0; i < 4; ++i) {
		string s; cin >> s;
		for(auto& c : s) m[c].insert(i);
	}
	for(auto& i : s) cin >> i;

	// for(auto it = m.begin(); it != m.end(); ++it) {
	// 	cout << it->first << ": ";
	// 	char c = it->first;
	// 	for(auto it2 = m[c].begin(); it2 != m[c].end(); ++it2) cout << *it2 << " ";
	// 	cout << endl;
	// }
	// cout << endl << endl;

	for(auto& curr : s) {
		auto sz = curr.size();
		vector<vector<int>> temp(sz);
		unordered_set<int> used;
		for(int i = 0; i < sz; ++i) {
			for(auto it = m[curr[i]].begin(); it != m[curr[i]].end(); ++it)
				temp[i].push_back(*it);
		}
	
		for(auto& v : temp)
			for(auto& i : v) used.insert(i);
		if(used.size() >= curr.size()) cout << "YES" << "\n";
		else cout << "NO" << "\n";

	}
		
}

// MOOOOF
// OOMOOO
// ABCDEF
// UVWRXY

// M O F A B C D E U V W R X Y
// 0 0 0 2 2 2 2 2 3 3 3 3 3 3
// 1 1 2 

// F A R M
// 0 2 3 0
// 2     1

// F M
// 0 0
// 2 1