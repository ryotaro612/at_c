#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const MOD = 10007ll;

ll solve(ll n) {
    ll const mx = 1000001;
    vector<ll> a(mx, 0);
    a[1] = a[2] = 0;
    a[3] = 1;
    for(ll i = 4ll; i < mx; i++) {
        a[i] = (((a[i - 1] + a[i - 2]) % MOD) + a[i - 3]) % MOD;
    }
    return a[n];
}
/*
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
*/