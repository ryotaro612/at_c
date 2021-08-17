#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> par;

void init(int n) {
    par.resize(n);
    for(int i = 0; i < n; i++)
        par[i] = -1;
}

int root(int i) {
    if(par[i] < 0)
        return i;
    return par[i] = root(par[i]);
}

bool same(int a, int b) { return root(a) == root(b); }

void merge(int a, int b) {
    if(same(a, b))
        return;

    int r_a = root(a), r_b = root(b);

    par[r_a] += par[r_b];
    par[r_b] = r_a;
}

int size(int a) { return -par[root(a)]; }

//#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> u(n - 1), v(n - 1);
    vector<ll> w(n - 1);
    vector<pair<ll, pair<int, int>>> p(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
        p[i] = {w[i], {u[i], v[i]}};
    }
    sort(p.begin(), p.end());
    ll ans = 0ll;
    init(n);
    for(auto e : p) {
        ll weight = e.first;
        int a = e.second.first, b = e.second.second;
        ans += weight * size(a) * size(b);
        merge(a, b);
    }
    cout << ans << endl;

    return 0;
}
// #endif