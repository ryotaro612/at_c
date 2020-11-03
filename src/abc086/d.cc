#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k, vector<ll> x, vector<ll> y, vector<char> c) {
    vector<vector<ll>> s(4000, vector<ll>(4000, 0));
    for(ll i = 0; i < n; i++) {
        if(c[i] == 'B') {
            s[x[i] % (2 * k)][y[i] % (2 * k)] += 1;
        } else {
            s[x[i] % (2 * k)][(y[i] + k) % (2 * k)] += 1;
        }
    }

    for(ll i = 0; i < 2 * k; i++) {
        for(ll j = 1; j < 2 * k; j++) {
            s[i][j] += s[i][j - 1];
        }
    }
    for(ll i = 1; i < 2 * k; i++) {
        for(ll j = 0; j < 2 * k; j++) {
            s[i][j] += s[i - 1][j];
        }
    }

    ll res = s[2 * k - 1][k - 1] - s[k - 1][k - 1] + s[k - 1][2 * k - 1] -
             s[k - 1][k - 1];
    for(ll i = 0; i < k; i++) {
        for(ll j = 0; j < k; j++) {
            ll temp = s[i][j];
            ll b = s[i][2 * k - 1] - s[i][j + k];
            temp += b;
            ll c = s[i + k][j + k] - s[i + k][j] - s[i][j + k] + s[i][j];
            temp += c;
            ll d = s[2 * k - 1][j] - s[i + k][j];
            temp += d;
            ll e = s[2 * k - 1][2 * k - 1] - s[2 * k - 1][j + k] -
                   s[i + k][2 * k - 1] + s[i + k][j + k];
            temp += e;
            res = max(n - temp, max(temp, res));
        }
    }
    return res;
}
/*
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    vector<char> c(n);

    for(ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }

    cout << solve(n, k, x, y, c);
}
*/