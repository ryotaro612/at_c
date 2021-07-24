#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, int q, vector<ll> a, vector<int> b, vector<int> c,
           vector<int> d) {
    for(int i = 0; i < n; i++)
        b[i]--;
    for(int i = 0; i < q; i++) {
        c[i]--;
        d[i]--;
    }
    vector<multiset<ll>> g(200000);
    for(int i = 0; i < n; i++)
        g[b[i]].insert(a[i]);

    multiset<ll> mx;
    for(auto gg : g) {
        if(gg.empty())
            continue;
        auto iter = gg.end();
        mx.insert(*(--iter));
    }
    for(int i = 0; i < q; i++) {
        auto iter = g[b[c[i]]].end();
        iter--;
        ll y_rate = a[c[i]];
        if(y_rate == *iter) {
            mx.erase(mx.lower_bound(y_rate));
            g[b[c[i]]].erase(g[b[c[i]]].lower_bound(y_rate));
            if(!g[b[c[i]]].empty()) {
                auto iter2 = g[b[c[i]]].end();
                mx.insert(*(--iter2));
            }
        } else {
            g[b[c[i]]].erase(g[b[c[i]]].lower_bound(y_rate));
        }
        b[c[i]] = d[i]; // 新しい場所
        if(g[d[i]].empty()) {
            mx.insert(y_rate);
            g[d[i]].insert(y_rate);
        } else {
            auto iter = g[d[i]].end();
            iter--;
            if(*iter >= y_rate) {
                g[d[i]].insert(y_rate);
            } else { // *iter < y_rate
                mx.erase(mx.lower_bound(*iter));
                mx.insert(y_rate);
                g[d[i]].insert(y_rate);
            }
        }
        cout << *(mx.begin()) << endl;
    }
}

#ifndef _LOCAL
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<int> b(n), c(q), d(q);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(int i = 0; i < q; i++)
        cin >> c[i] >> d[i];

    solve(n, q, a, b, c, d);
    return 0;
}
#endif