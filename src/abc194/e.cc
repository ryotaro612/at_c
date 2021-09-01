#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(ll n, ll m, vector<ll> a) {
    vector<ll> sum(n + 1, 0ll), mex(n - m + 1ll);
    for(ll i = 0ll; i < m; i++)
        sum[a[i]]++;
    ll mv = 0ll;
    while(sum[mv] > 0ll)
        mv++;
    mex[0] = mv;
    for(ll i = m; i < n; i++) {
        sum[a[i]]++;
        sum[a[i - m]]--;
        if(sum[a[i - m]] == 0ll && a[i - m] < mv)
            mv = a[i - m];
        while(sum[mv] > 0ll)
            mv++;
        mex[i - m + 1] = mv;
    }
    ll res = n + 1;
    for(auto m : mex)
        res = min(res, m);
    return res;
}

#ifndef _debug
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, m, a) << endl;
    return 0;
}
#endif