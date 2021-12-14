#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int root(int index, vector<int> &par) {
    if(par[index] < 0)
        return index;
    return par[index] = root(par[index], par);
}
bool same(int a, int b, vector<int> &par) {
    return root(a, par) == root(b, par);
}
void unite(int a, int b, vector<int> &par) {
    int root_a = root(a, par), root_b = root(b, par);
    if(root_a == root_b)
        return;

    if(par[root_a] < par[root_b]) {
        par[root_a] += par[root_b];
        par[root_b] = root_a;
    } else {
        par[root_b] += par[root_a];
        par[root_a] = root_b;
    }
}

int solve(int n, int m, vector<int> &x, vector<int> &y, vector<int> &z) {
    vector<int> par(n, -1);
    unordered_set<int> groups;
    rep(i, m) { unite(--x[i], --y[i], par); }
    rep(i, n) {
        groups.insert(root(i, par));
    }
    return groups.size();
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m), z(m);
    rep(i, m) cin >> x[i] >> y[i] >> z[i];
    cout << solve(n, m, x, y, z) << endl;
    return 0;
}
#endif