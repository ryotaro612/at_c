#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll INF = 10000000000ll;
ll solve(int n, int m, vector<ll> a, vector<ll> b, vector<ll> t) {
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for(int i = 0; i < n; i++) {
        d[i][i] = 0ll;
    }
    for(int i = 0; i < m; i++) {
        d[a[i] - 1][b[i] - 1] = d[b[i] - 1][a[i] - 1] = t[i];
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
#ifdef _LOCAL
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
#endif
    ll res = INF;
    // iは引っ越した場所
    for(int i = 0; i < n; i++) {
        ll temp = 0ll;
        for(int j = 0; j < n; j++) {
            temp = max(temp, d[i][j]);
        }
        res = min(temp, res);
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), t(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> t[i];
    }
    cout << solve(n, m, a, b, t) << endl;
    return 0;
}
#endif
