#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const ll MOD = 998244353ll;

ll solve(int n, vector<ll> &a) {
	// 転倒数?
	// dp[i][j] iまでで長さj
}

#ifndef _debug
int main() {
    int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n)
		cin >> a[i];
	cout << solve(n, a) << endl;
    return 0;
}
#endif