#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
ll const MOD = 998244353ll;

struct UnionFind {
    vector<int> par;
    UnionFind(int n) { par = vector<int>(n, -1); }
    int find(int i) {
        if(par[i] < 0)
            return i;
        return par[i] = find(par[i]);
    }
    bool same_group(int a, int b) { return find(a) == find(b); }
    int size(int n) { return -par[find(n)]; }

    void unite(int a, int b) {
        if(find(a) == find(b))
            return;
        int root_a = find(a);
        int root_b = find(b);
        if(par[root_a] < par[root_b]) {
            par[root_a] += par[root_b];
            par[root_b] = root_a;
        } else {
            par[root_b] += par[root_a];
            par[root_a] = root_b;
        }
    }
};

ll count_patterns(vector<pair<int, int>> &edges) {
    set<int> nodes;
    for(auto edge : edges) {
        nodes.insert(edge.first);
        nodes.insert(edge.second);
    }
    if(edges.size() == nodes.size())
        return 2ll;
    return 0ll;
}

ll solve(int n, int m, vector<int> &u, vector<int> &v) {
    UnionFind uf(n);
    rep(i, m) {
        u[i]--;
        v[i]--;
        uf.unite(u[i], v[i]);
    }
    rep(i, n) {
        if(uf.size(i) == 1)
            return 0;
    }
    unordered_map<int, vector<pair<int, int>>> groups;
    rep(i, m) { groups[uf.find(u[i])].push_back({u[i], v[i]}); }
    ll res = 1ll;
    for(auto group : groups) {
        res *= count_patterns(group.second);
        res %= MOD;
    }
    return res;
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    rep(i, m) cin >> u[i] >> v[i];
    cout << solve(n, m, u, v) << endl;
    return 0;
}
#endif