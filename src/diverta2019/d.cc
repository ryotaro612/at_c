#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> calc_divisors(ll n) {
    vector<ll> ans;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0ll) {
            ans.push_back(i);
            if(i * i != n)
                ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

ll solve(ll n) {
    vector<ll> divisors = calc_divisors(n);
    ll ans = 0ll;
    for(auto divisor : divisors) {
        ll m = n / divisor - 1;
        if(m > 0 && n / m == n % m) {
            ans += m;
        }
    }
    return ans;
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif