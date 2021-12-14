#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> par;

ll find(ll i) {
    if(par[i] == i)
        return i;
    return par[i] = find(par[i]);
}

bool is_same(ll a, ll b) { return find(a) == find(b); }

void unite(ll a, ll b) {
    ll g_a = find(a), g_b = find(b);
    par[g_a] = g_b;
}

ll solve(ll n, ll m, vector<ll> a, vector<ll> b) {
    par.resize(n);
    for(int i = 0; i < n; i++)
        par[i] = i;

    for(int i = 0; i < m; i++)
        unite(--a[i], --b[i]);

    set<ll> ans;
    for(int i = 0; i < n; i++) {
        ans.insert(find(i));
    }
    return (int)ans.size() - 1;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    cout << solve(n, m, a, b) << endl;

    return 0;
}
#endif