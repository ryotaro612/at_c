#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long calc_pow(ll x, ll n) {
    ll ret = 1;
    while(n > 0) {
        if(n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

vector<ll> calc_divisors(ll n) {
    vector<ll> ans;
    for(ll i = 1ll; i * i <= n; i++) {
        if(n % i == 0ll) {
            ans.push_back(i);
            if(i != n / i)
                ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

ll solve(ll n, ll p) {
    vector<ll> divisors = calc_divisors(p);
    /*
    for(auto d : divisors) {
        cout << d << endl;
    }
    cout << " -- " << endl;
    */
    ll ans = 1;
    for(ll i = 1ll; i < (ll)divisors.size(); i++) {
        ll count = 0ll;
        ll a = p;
        while(a % divisors[i] == 0ll) {
            a /= divisors[i];
            count++;
        }
        if(n <= count)
            ans = divisors[i];
        /*
        else
            return ans;
            */
    }
    return ans;
}
#ifndef _LOCAL
int main() {
    ll n, p;
    cin >> n >> p;
    cout << solve(n, p) << endl;
    return 0;
}
#endif