// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> aidx(n);
	vector<int> bidx(n);
	vector<int> diff(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		aidx[a[i]-1] = i;
	} 
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		bidx[b[i]-1] = i;
	}

	int mn = 10e6;
	int res = 0;
	int mnidx = -1;
	bool good = true;
	for(int i = 0; i < n; ++i) {
		diff[i] = bidx[i] - aidx[i];
		if(diff[i]) good = false;
		if(diff[i] < mn) {
			mn = min(mn, diff[i]);
			mnidx = i;
		}
	}


	// for(auto& i : a) cout << i << " ";
	// cout << endl;
	// for(auto& i : b) cout << i << " ";
	// cout << endl;
	// for(auto& i : aidx) cout << i << " ";
	// cout << endl;
	// for(auto& i : bidx) cout << i << " ";
	// cout << endl;
	// for(auto& i : diff) cout << i << " ";
	// cout << endl;
	int t = 10;
	while(mn && !good && t) {
		mn = 10e6;
		for(int i = 0; i < n; ++i) {
			diff[i] = bidx[i] - aidx[i];
			if(diff[i] < mn) {
				mn = min(mn, diff[i]);
				mnidx = i;
			}
		}

		if(!mn) continue;
		// cout << mnidx << endl;
		// for(auto& i : diff) cout << i << " ";
		// cout << endl;

		a.insert(a.begin()+(n+mn-1), mnidx+1);
		a.erase(a.begin()+aidx[mnidx]+1);

		for(int i = 0; i < n; ++i) aidx[a[i]-1] = i;

		// for(auto& i : a) cout << i << " ";
		// cout << endl;
		// for(auto& i : aidx) cout << i << " ";
		// cout << endl;


		// cout << mn << endl;
		// cout << endl << endl;
		++res;
	}

	cout << res << endl;


}
