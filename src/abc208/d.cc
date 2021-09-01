#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll INF = 100000000000000ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<ll> c(m);
    ll ans = 0ll;
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        d[a[i]][b[i]] = c[i];
    }
    for(int i = 0; i < n; i++)
        d[i][i] = 0ll;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if(d[i][j] < INF)
                    ans += d[i][j];
            }
        }
    }
    cout << ans << endl;
}

#ifndef _debug
int main() {
    solve();
    return 0;
}
#endif
