#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int find_root(int index, vector<int> &par) {
    if(par[index] < 0)
        return index;
    return par[index] = find_root(par[index], par);
}

bool same_group(int a, int b, vector<int> &par) {
    return find_root(a, par) == find_root(b, par);
}

void unite(int a, int b, vector<int> &par,
           vector<unordered_map<int, int>> &cls) {
    if(same_group(a, b, par))
        return;
    int root_a = find_root(a, par), root_b = find_root(b, par);
    if(par[root_a] < par[root_b]) {
        par[root_a] += par[root_b];
        par[root_b] = root_a;
        for(auto e : cls[root_b]) {
            cls[root_a][e.first] += e.second;
        }
    } else {
        par[root_b] += par[root_a];
        par[root_a] = root_b;
        for(auto e : cls[root_a]) {
            cls[root_b][e.first] += e.second;
        }
    }
}

vector<int> solve(int n, int q, vector<int> &c,
                  vector<pair<int, pair<int, int>>> &queries) {
    vector<int> par(n, -1);
    // 生徒iをrootとするグループにはクラスjの生徒がcls[i][j]人いいる
    vector<unordered_map<int, int>> cls(n);
    rep(i, n) {
        c[i]--;
        cls[i][c[i]] = 1;
    }
    vector<int> res;
    rep(i, q) {
        if(queries[i].first == 1) {
            int a = queries[i].second.first - 1;
            int b = queries[i].second.second - 1;
            unite(a, b, par, cls);
        } else {
            int x = queries[i].second.first - 1;
            int y = queries[i].second.second - 1;
            int root = find_root(x, par);
            res.push_back(cls[root][y]);
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    vector<pair<int, pair<int, int>>> queries(q);
    rep(i, q) {
        int a, b, c;
        cin >> a >> b >> c;
        queries[i] = {a, {b, c}};
    }
    vector<int> res = solve(n, q, c, queries);
    for(auto e : res)
        cout << e << endl;

    return 0;
}
#endif