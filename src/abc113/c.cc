#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string encode(ll v) {
    string suffix = to_string(v);
    string prefix = "";
    for(int i = 0; i < 6 - (int)suffix.size(); i++) {
        prefix.push_back('0');
    }
    return prefix + suffix;
}

vector<string> solve(int n, int m, vector<ll> P, vector<ll> Y) {
    for(int i = 0; i < m; ++i)
        --P[i];

    // vals[v] := P[i] = v であるような i についての Y[i] の値を集めたもの
    vector<vector<int>> vals(n);
    for(int i = 0; i < m; ++i)
        vals[P[i]].push_back(Y[i]);

    // 各 p の値に対して
    for(int v = 0; v < n; ++v) {
        sort(vals[v].begin(), vals[v].end());

        // 今回は不要だが、通常は数のダブりをなくす
        vals[v].erase(unique(vals[v].begin(), vals[v].end()), vals[v].end());
    }
    vector<string> res(m);
    // 答え
    for(int i = 0; i < m; ++i) {
        int v = P[i];
        string prefix = encode(v + 1);
        // 座標圧縮して導いた答え
        int id =
            lower_bound(vals[v].begin(), vals[v].end(), Y[i]) - vals[v].begin();
        string suffix = encode(id + 1);
        res[i] = prefix + suffix;
    }
    return res;
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> pv(m), yv(m);
    for(int i = 0; i < m; i++) {
        cin >> pv[i] >> yv[i];
    }
    vector<string> res = solve(n, m, pv, yv);
    for(auto aa : res)
        cout << aa << endl;
    return 0;
}
#endif
