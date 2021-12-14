#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<ll, int>> p(n);
    for(int i = 0; i < n; i++) {
        p[i] = {a[i], i};
    }
    sort(p.begin(), p.end());

    ll base = k / n, remain = k % n;
    vector<ll> ans(n, base);
    for(int i = 0; i < n; i++) {
        if(i + 1 <= remain) {
            ans[p[i].second] += 1ll;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}

#ifdef ONLINE_JUDGE
int main() {

    solve();
    return 0;
}
#endif