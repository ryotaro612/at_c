#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> calc_divisors(ll v) {
    vector<ll> res;
    for(ll i = 1ll; i * i <= v; i++) {
        if(v % i == 0ll) {
            res.push_back(i);
            if(i * i != v)
                res.push_back(v / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

string calc(ll v) {
    map<ll, ll> primes;
    for(ll i = 2ll; i * i <= v; i++) {
        while(v % i == 0) {
            primes[i]++;
            v /= i;
        }
    }
    if(v != 1)
        primes[v] = 1;

    ll odd = 1;
    for(auto pp : primes) {
        if(pp.first != 2)
            odd *= pp.second + 1;
    }
    ll even = primes[2] * odd;
    if(even > odd)
        return "Even";
    if(even == odd)
        return "Same";
    else
        return "Odd";
}

vector<string> solve(int t, vector<ll> cases) {
    vector<string> res(t);
    for(int i = 0; i < t; i++)
        res[i] = calc(cases[i]);
    return res;
}

#ifndef _LOCAL
int main() {
    int t;
    cin >> t;
    vector<ll> cases(t);
    for(int i = 0; i < t; i++)
        cin >> cases[i];
    vector<string> res = solve(t, cases);
    for(auto aa : res)
        cout << aa << endl;
}
#endif