#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int m, int r, vector<int> rv, vector<ll> a, vector<ll> b,
          vector<ll> c) {
    ll mx = pow(10, 9);
    vector<vector<ll>> d(n, vector<ll>(n, mx));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = mx;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        d[a[i] - 1][b[i] - 1] = c[i];
        d[b[i] - 1][a[i] - 1] = c[i];
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    sort(rv.begin(), rv.end());
    ll res = mx;
    do {
        ll temp = 0;
        for(int i = 0; i < r - 1; i++) {
            temp += d[rv[i] - 1][rv[i + 1] - 1];
        }
        res = min(res, temp);
    } while(next_permutation(rv.begin(), rv.end()));

    return res;
}
/*
int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> rv(r);
    for(int i = 0; i < r; i++) {
        cin >> rv[i];
    }
    vector<ll> a(m), b(m), c(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << solve(n, m, r, rv, a, b, c);
}
*/