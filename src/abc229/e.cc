//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) {}
    int find_root(int i) {
        if(par[i] < 0)
            return i;
        return par[i] = find_root(par[i]);
    }
    bool same_group(int a, int b) { return find_root(a) == find_root(b); }
    void unite(int a, int b) {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if(root_a < root_b) {
            par[root_a] += par[root_b];
            par[root_b] = root_a;
        } else {
            par[root_b] += par[root_a];
            par[root_a] = root_b;
        }
    }
};

vector<int> solve(int n, int m, vector<int> &a, vector<int> &b) {
    vector<int> res;
    UnionFind uf(n);
    unordered_map<int, set<int>> mp;
    rep(i, m) {
        mp[--a[i]].insert(--b[i]);
        mp[b[i]].insert(a[i]);
    }
    int current = 0;
    for(int i = n - 1; i >= 0; i--) {
        res.push_back(current);
        set<int> nodes(upper_bound(mp[i].begin(), mp[i].end(), i), mp[i].end());
        current++;
        for(auto node : nodes) {
            if(uf.same_group(i, node)) {

            } else {
                current--;
                uf.unite(i, node);
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    vector<int> res = solve(n, m, a, b);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif