#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(ll n, ll w, vector<ll> &a, vector<ll> &b) {
    vector<pair<ll, ll>> ab(n);
    rep(i, n) ab[i] = {a[i], b[i]};
    sort(ab.begin(), ab.end(), greater<pair<ll, ll>>());
    ll weight = 0ll, res = 0ll;
    rep(i, n) {
        ll delta = min(ab[i].second, w - weight);
        res += ab[i].first * delta;
        weight += delta;
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    cout << solve(n, w, a, b) << endl;
    return 0;
}
#endif