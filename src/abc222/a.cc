#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(string s) {
	string zeros(4-s.size(), '0');
	return zeros + s;
}

#ifndef _debug
int main() {
	string n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
#endif