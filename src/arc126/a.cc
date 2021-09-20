#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<ll> solve(int t, vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    vector<ll> ans(t, 0ll);
    rep(i, t) {
        ll n2 = a[i], n3 = b[i], n4 = c[i];
        // 3 * 2 + 4 * 1
        ans[i] = min(n3 / 2ll, n4);
        n3 -= ans[i] * 2ll;
        n4 -= ans[i];
        // 4 * 2 + 2 * 1
        ll p4x22 = min(n4 / 2ll, n2);
        ans[i] += p4x22;
        n4 -= p4x22 * 2ll;
        n2 -= p4x22;
        // 3*2 + 2 * 2
        ll p3x22x2 = min(n3 / 2ll, n2 / 2ll);
        ans[i] += p3x22x2;
        n3 -= p3x22x2 * 2ll;
        n2 -= p3x22x2 * 2ll;
        // 4 + 2 * 3
        ans[i] += min(n4, n2 / 3ll);
        n2 -= min(n4, n2 / 3ll) * 3ll;
        // 2 * 5
        ans[i] += n2 / 5ll;
    }
    return ans;
}

#ifndef _debug
int main() {
    int t;
    cin >> t;
    vector<ll> a(t), b(t), c(t);
    rep(i, t) cin >> a[i] >> b[i] >> c[i];

    vector<ll> res = solve(t, a, b, c);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif