#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static ll MOD = 1000000007ll;

ll mul(ll a, ll b) { return (a * b) % MOD; }

ll solve(ll n, vector<int> a) {
    vector<int> c(n + 1, 0);
    ll res = 1ll;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            if(c[0] == 0)
                res = mul(res, 3);
            else if(c[0] == 1)
                res = mul(res, 2);
        } else {
            if(c[a[i] - 1] == 3 && c[a[i]] == 0)
                res = mul(res, 3);
            else if(c[a[i] - 1] == 3 && c[a[i]] == 1)
                res = mul(res, 2);
            else if(c[a[i] - 1] == 2 && c[a[i]] == 0)
                res = mul(res, 2);
        }
        c[a[i]]++;
        //cout << i << " -> " << res << endl;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}
#endif