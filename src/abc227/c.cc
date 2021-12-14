#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(ll n) {
    ll d = 1ll;
    for(;; d++) {
        if(n < (d + 1ll) * (d + 1ll) * (d + 1ll)) {
			d++;
            break;
        }
    }
	//cout << d << endl;
    ll res = 0ll;
    for(ll a = 1ll; a <= d; a++) {
        for(ll b = a; b <= n / a; b++) {
            ll delta = n / (a * b) - b + 1;
			//cout << a << " " << b << " -> " << delta << endl;
            if(delta > 0)
                res += delta;
            else
                break;
        }
    }
    return res;
}
#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif