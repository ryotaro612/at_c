#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, vector<ll> a, vector<ll> p, vector<ll> x) {
    ll res = -1ll;
    for(int i = 0; i < n; i++) {
        if(x[i] - a[i] > 0) {
            if(res < 0 || p[i] < res)
                res = p[i];
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), p(n), x(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> x[i];
    }
    cout << solve(n, a, p, x) << endl;
    return 0;
}
#endif