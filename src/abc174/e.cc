#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ub = 1000000001ll, lb = 0ll;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2ll, count = 0ll;

        for(int i = 0; i < n; i++)
            count += (a[i] - 1ll) / mid;
		if(count <= k)
			ub = mid;
		else
			lb = mid;
    }
	cout << ub << endl;
    return 0;
}
#endif
