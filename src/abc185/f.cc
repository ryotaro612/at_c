#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> bit(300001, 0);

ll sum(ll i) {
    ll s = 0ll;
    while(i > 0) {
        s ^= bit[i];
        i -= i & -i;
    }
    return s;
}

void add(ll i, ll x, ll n) {
    while(i <= n) {
        bit[i] ^= x;
        i += i & -i;
    }
}

vector<ll> solve(int n, int q, vector<ll> a, vector<ll> t, vector<ll> x,
                 vector<ll> y) {
    vector<ll> res;
    for(int i = 0; i < n; i++)
        add(i + 1, a[i], n);
    for(int i = 0; i < q; i++) {
        if(t[i] == 1) {
            add(x[i], y[i], n);
        } else {
            res.push_back(sum(x[i] - 1) ^ sum(y[i]));
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> t(q), x(q), y(q);
    for(int i = 0; i < q; i++)
        cin >> t[i] >> x[i] >> y[i];
    vector<ll> res = solve(n, q, a, t, x, y);
    for(auto r : res)
        cout << r << endl;
}
#endif