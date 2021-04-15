#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k, vector<ll> &a) {
    vector<ll> b(n);
    ll i = 0ll;
    while(i < n) {
        ll peek = i;
        while(peek < n - 1 && a[peek] < a[peek + 1]) {
            peek++;
        }
        for(ll j = i; j <= peek; j++)
            b[j] = peek;
        i = peek + 1;
    }
    ll res = 0ll;
    for(ll i = 0ll; i < n; i++) {
        if(b[i] - i + 1 >= k)
            res++;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, k, a) << endl;
    return 0;
}
#endif