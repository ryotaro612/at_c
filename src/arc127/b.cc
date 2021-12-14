#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<(int)(n);i++)

// vector<string> solve(int n, int l) {

// }

#ifdef ONLINE_JUDGE
int main() {
	int n, l;
	cin >> n >> l;
	vector<string> res = solve(n, l);
	for(auto e: res)
		cout << e << endl;
	return 0;
}
#endif