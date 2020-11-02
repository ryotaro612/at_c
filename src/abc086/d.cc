#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k, vector<ll> x, vector<ll> y, vector<ll> c) {
    vector<vector<ll>> a(2 * k, vector<ll>(2 * k, 0));
    for(ll i = 0; i < n; i++) {
        if(c[i] == 'B') {
            a[x[i] % (2 * k)][y[i] % (2 * k)] += 1;
        } else {
            a[(x[i] + k) % (2 * k)][(y[i] + k) % (2 * k)] += 1;
        }
    }
    vector<vector<ll>> s(4000, vector<ll>(4000, 0));
    s[0][0] = a[0][0];
    for(ll j = 1; j < 2 * k; j++) {
        s[0][j] = s[0][j - 1] + a[0][j];
    }
    for(ll i = 1; i < 2 * k; i++) {
        s[i][0] = s[i - 1][0] + a[i][0];
    }
    for(ll i = 1; i < 2 * k; i++) {
        for(ll j = 1; j < 2 * k; j++) {
            s[i][j] = s[i - 1][j - 1] + (s[i][j - 1] - s[i - 1][j - 1]) +
                      (s[i - 1][j] - s[i - 1][j - 1]) + a[i][j];
        }
    }
    for(ll i = 0; i < 5; i++) {
        for(ll j = 0; j < 5; j++) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    ll res = s[2 * k - 1][k - 1] - s[k - 1][k - 1] + s[k - 1][2 * k - 1] -
             s[k - 1][k - 1];
    for(ll i = 0; i < k; i++) {
        for(ll j = 0; j < k; j++) {
            ll temp = s[i][j];
            temp += s[i][2 * k - 1] - s[i][j + k];
            temp += s[i + k][j + k] - s[i + k][j] - s[i][j + k];
            temp += s[2 * k - 1][j] - s[i + k][j];
            temp += s[2 * k - 1][2 * k - 1] - s[2 * k - 1][j + k] -
                    s[i + k][2 * k - 1] + s[i + k][j + k];
            res = max(temp, res);
        }
    }
    return res;
}
/*
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n), c(n);

    for(ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }

    cout << solve(n, k, x, y, c);
}
*/