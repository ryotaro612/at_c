#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, ll k, vector<ll> h) {
    sort(h.begin(), h.end());
    ll res = 0ll;
    for(ll i = 0ll; i < n - k; i++) {
        res += h[i];
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    cout << solve(n, k, h) << endl;
}
#endif