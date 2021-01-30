#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll n, ll s, ll d, vector<ll> x, vector<ll> y) {
    for(ll i = 0ll; i < n; i++) {
        if(x[i] < s && y[i] > d) {
            return "Yes";
        }
    }
    return "No";
}
/*
int main() {
    ll n, s, d;
    cin >> n >> s >> d;
    vector<ll> x(n), y(n);
    for(ll i = 0ll; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, s, d, x, y) << endl;
}
*/