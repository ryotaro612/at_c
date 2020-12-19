#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll MOD = pow(10, 9) + 7;

ll solve(int n, int m, vector<ll> x, vector<ll> y) {
    ll xx = 0;
    for(int i = 1; i <= n; i++) {
        xx += ((i - 1 - n + i) * x[i - 1]);
        xx %= MOD;
    }
    ll yy = 0;
    for(int i = 1; i <= m; i++) {
        yy += ((i - 1 - m + i) * y[i - 1]);
        yy %= MOD;
    }
    return (xx * yy) % MOD;
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> y[i];
    }
    cout << solve(n, m, x, y);
}
*/