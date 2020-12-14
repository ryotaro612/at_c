#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ceil(ll a, ll b) {
    if(a % b == 0) {
        return a / b;
    }
    return (a / b) + 1;
}

ll solve(ll n, ll m, vector<ll> a) {
    if(m == 0) {
        return 1;
    }
    if((int)a.size() == n) {
        return 0;
    }
    ll w = n;
    sort(a.begin(), a.end());
    if(a[0] != 1) {
        w = min(a[0] - 1, w);
    }
    if(a[m - 1] != n) {
        w = min(n - a[m - 1], w);
    }

    for(int i = 0; i < m - 1; i++) {
        if(a[i + 1] - a[i] - 1 != 0)
            w = min(a[i + 1] - a[i] - 1, w);
    }
    ll res = 0;
    for(int i = 0; i < m; i++) {
        if(i == 0) {
            res += ceil(a[0] - 1, w);
            continue;
        }
        res += ceil(a[i] - a[i - 1] - 1, w);
    }
    res += ceil(n - a[m - 1], w);

    return res;
}
/*
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    cout << solve(n, m, a);
}
*/