#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool same_cost(int m, vector<ll> &c, vector<ll> &d) {
    ll sum_c = 0ll, sum_d = 0ll;
    for(int i = 0; i < m; i++) {
        sum_c += c[i];
        sum_d += d[i];
    }
    return sum_c == sum_d;
}
static const int MX = 200001;

int par[MX];

void init(int n) {
    for(int i = 0; i < n; i++)
        par[i] = i;
}

int find(int x) {
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    par[x] = y;
}

bool is_same(int x, int y) { return find(x) == find(y); }

string solve(int n, int m, vector<ll> a, vector<ll> b, vector<ll> c,
             vector<ll> d) {
    init(n);
    for(int i = 0; i < m; i++) {
        unite(c[i] - 1, d[i] - 1);
    }
    vector<vector<int>> nodes(n);
    for(int i = 0; i < n; i++)
        nodes[find(i)].push_back(i);
    
    for(auto group: nodes) {
        ll sum_a = 0ll, sum_b = 0ll;
        for(auto index: group) {
            sum_a += a[index];
            sum_b += b[index];
        }
        if(sum_a != sum_b)
            return "No";
    }
    return "Yes";
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
    cout << solve(n, m, a, b, c, d) << endl;
    return 0;
}
#endif