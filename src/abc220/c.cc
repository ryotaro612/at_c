#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(ll n, vector<ll> &a, ll x) {
    ll sum = 0ll;
    rep(i, n) sum += a[i];
    ll res = (x / sum) * n;
    x -= ((x / sum) * sum);
    for(int i = 0;; i++) {
        x -= a[i];
        res++;
        if(x < 0ll)
            return res;
    }
    return -1ll;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll x;
    cin >> x;
    cout << solve(n, a, x) << endl;
    return 0;
}
#endif