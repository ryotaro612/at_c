#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll a, ll b, ll c, ll d, ll e) {

    vector<ll> pass = {a, b, c, d, e};
    ll narrow = numeric_limits<ll>::max();
    int n_i;
    for(int i = 0; i < 5; i++) {
        if(narrow > pass[i]) {
            narrow = pass[i];
            n_i = i;
        }
    }
    if(n % pass[n_i] == 0ll) {
        return n / pass[n_i] + 4ll;
    } else {
        return n / pass[n_i] + 5ll;
    }
    /*

    if(n_i == 0) {
        if(n % pass[n_i] == 0ll) {
            return n / pass[n_i] + 5ll;
        } else {
            return n / pass[n_i] + 1ll + 5ll;
        }
    } else if(n_i == 1) {
    }
    */
}

#ifndef _LOCAL
int main() {
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    cout << solve(n, a, b, c, d, e) << endl;
    return 0;
}
#endif