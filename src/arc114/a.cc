#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if(a == 0ll)
        return b;
    return gcd(b % a, a);
}

ll solve(ll n, vector<ll> x) {
    vector<ll> primes = {2ll,  3ll,  5ll,  7ll,  11ll, 13ll, 17ll, 19ll,
                         23ll, 29ll, 31ll, 37ll, 41ll, 43ll, 47ll};
    vector<ll> cands;
    for(ll i = 1ll; i < (1ll << 15ll); i++) {
        ll cand = 1ll;
        for(ll j = 0ll; j < 15ll; j++) {
            if(i & (1ll << j))
                cand *= primes[j];
        }
        bool ok = true;
        for(ll k = 0ll; k < n; k++) {
            if(gcd(max(cand, x[k]), min(cand, x[k])) == 1ll) {
                ok = false;
                break;
            }
        }
        if(ok)
            cands.push_back(cand);
    }
    sort(cands.begin(), cands.end());
    return cands[0];
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    vector<ll> x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];
    cout << solve(n, x) << endl;
}
#endif

/*
ll lcm(ll a, ll b) { return (a * b) / gcd(max(a, b), min(a, b)); }

vector<ll> factorize(ll n) {
    vector<ll> res;
    for(ll i = 2ll; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n != 1)
        res.push_back(n);
    sort(res.begin(), res.end());
    return res;
}
*/