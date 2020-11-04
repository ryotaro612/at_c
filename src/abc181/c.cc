#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

string solve(ll n, vector<ll> x, vector<ll> y) {

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                cout << i << " " << j << " " << k << endl;
                ll x0 = x[j] - x[i];
                ll y0 = y[j] - y[i];
                ll x1 = x[k] - x[i];
                ll y1 = y[k] - y[i];
                if(x1 * y0 == y1 * x0) {
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
/*
int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, x, y);
}
*/