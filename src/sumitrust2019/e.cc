#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int C[3];
long long sum = 1;

ll solve(ll n, vector<int> a) {
	for (int i = 0; i < n; i++) {
		long long cnt = 0, id = -1;
		if (a[i] == C[0]) { cnt++; id = 0; }
		if (a[i] == C[1]) { cnt++; id = 1; }
		if (a[i] == C[2]) { cnt++; id = 2; }
		if (id == -1) {
			return 0;
		}
		sum *= cnt; C[id]++;
		sum %= 1000000007;
	}
    return sum;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}
#endif