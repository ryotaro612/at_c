#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(int n, vector<ll> &t, vector<int> &k, vector<vector<int>> &a) {
	vector<bool> used(n, false); 
	rep(i, n) {
		rep(j, a[i].size())
			a[i][j]--;
	}
	ll res = 0ll;
	queue<int> que;
	que.push(n-1);
	used[n-1] = true;
	while(!que.empty()) {
		int skill_i = que.front();
		que.pop();
		res += t[skill_i];
		rep(i, k[skill_i]) {
			if(!used[a[skill_i][i]]) {
				used[a[skill_i][i]] = true;
				que.push(a[skill_i][i]);
			}
		}
	}
	return res;
}

#ifndef _debug
int main() { 
	int n;
	cin >> n;
	vector<ll> t(n);
	vector<int> k(n);
	vector<vector<int>> a;
	rep(i, n) {
		cin >> t[i] >> k[i];
		vector<int> b(k[i]);
		rep(j, k[i])
			cin >> b[j];
		a.push_back(b);
	}
	cout << solve(n, t, k, a) << endl;

	return 0; 
}
#endif