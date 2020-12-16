#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
    ll from, to, cost;
};

pair<ll, string> solve(int n, int m, vector<ll> a, vector<ll> b, vector<ll> c) {
    vector<edge> es(m);
    for(int i = 0; i < m; i++) {
        es[i] = edge({a[i] - 1, b[i] - 1, -c[i]});
    }
    // long long max: 9,223,372,036,854,775,807;
    ll inf = 1LL << 50;
    vector<ll> d(n, inf);
    d[0] = 0;

    for(int i = 0; i < 2 * n; i++) {
        for(int j = 0; j < (int)es.size(); j++) {
            edge e = es[j];
            ll cand = d[e.from] + e.cost;
            if(d[e.from] != inf && d[e.to] > cand) {
                d[e.to] = cand;
                if(i == 2 * n - 1 && e.to == n - 1) {
                    return make_pair(0, "inf");
                }
            }
        }
    }
    return make_pair(-d[n - 1], "");
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    auto res = solve(n, m, a, b, c);
    if(res.second == "inf")
        cout << "inf";
    else {
        cout << res.first;
    }
}
*/