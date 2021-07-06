#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll, ll> P;

struct A {
    ll x0, x1, y0, y1;
    bool flip;
};

vector<P> solve(int n, int m, int q, vector<ll> x, vector<ll> y,
                vector<pair<int, ll>> ops, vector<int> a, vector<int> b) {

    vector<A> acc(m + 1);
    acc[0] = {0ll, 1ll, 0ll, 1ll, false};
    for(int i = 0; i < m; i++) {
        A c = acc[i];
        if(ops[i].first == 1) {
            acc[i + 1] = {c.y0, c.y1, -c.x0, -c.x1, !c.flip};
        } else if(ops[i].first == 2) {
            acc[i + 1] = {-c.y0, -c.y1, c.x0, c.x1, !c.flip};
        } else if(ops[i].first == 3) {
            acc[i + 1] = {2ll * ops[i].second - c.x0, -c.x1, c.y0, c.y1,
                          c.flip};
        } else {
            acc[i + 1] = {c.x0, c.x1, 2ll * ops[i].second - c.y0, -c.y1,
                          c.flip};
        }
    }
	/*
    for(auto ac : acc) {
        cout << ac.x0 << " " << ac.x1 << " " << ac.y0 << " " << ac.y1 << endl;
        cout << " ---- " << endl;
    }
	*/
    vector<pair<ll, ll>> ans(q);
    for(int i = 0; i < q; i++) {
        A c = acc[a[i]];
        ll xx = x[b[i] - 1], yy = y[b[i] - 1];
        if(c.flip) {
            ans[i] = {c.x0 + c.x1 * yy, c.y0 + c.y1 * xx};
        } else {
            ans[i] = {c.x0 + c.x1 * xx, c.y0 + c.y1 * yy};
        }
    }

    return ans;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int m;
    cin >> m;
    vector<pair<int, ll>> ops(m);
    for(int i = 0; i < m; i++) {
        int a;
        ll b = 0;
        cin >> a;
        if(a >= 3)
            cin >> b;
        ops[i] = {a, b};
    }
    int q;
    cin >> q;
    vector<int> a(q), b(q);
    for(int i = 0; i < q; i++)
        cin >> a[i] >> b[i];

    auto ans = solve(n, m, q, x, y, ops, a, b);
    for(auto a : ans)
        cout << a.first << " " << a.second << endl;

    return 0;
}
#endif
