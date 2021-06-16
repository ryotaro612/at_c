#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
    int to;
    ll cap;
    int rev;
};

vector<vector<edge>> g;
vector<bool> used;
static const ll INF = 100000000000ll;

void add_edge(int from, int to) {
    g[from].push_back({to, 1, (int)g[to].size()});
    g[to].push_back({from, 0, (int)g[from].size() - 1});
}

ll dfs(int v, int t, ll f) {
    if(v == t)
        return f;
    used[v] = true;
    for(int i = 0; i < (int)g[v].size(); i++) {
        if(!used[g[v][i].to] && g[v][i].cap > 0ll) {
            ll d = dfs(g[v][i].to, t, min(f, g[v][i].cap));
            if(d > 0ll) {
                g[v][i].cap -= d;
                g[g[v][i].to][g[v][i].rev].cap += d;
                return d;
            }
        }
    }
    return 0ll;
}

ll solve(int n, ll t, vector<ll> a) {
    vector<ll> small(n, INF);

    map<ll, vector<int>> mp;
    mp[a[0]].push_back(0);
    for(int i = 1; i < n; i++) {
        small[i] = min(a[i - 1], small[i - 1]);
        mp[a[i]].push_back(i);
    }
    ll unit = -1ll;
    for(int i = 1; i < n; i++)
        unit = max(unit, a[i] - small[i]);
    assert(unit > 0);

    vector<pair<int, int>> pairs;
    set<int> nodes;
    for(int i = 1; i < n; i++) {
        for(auto e : mp[a[i] - unit]) {
            if(e < i) {
                pairs.push_back({e, i});
                nodes.insert(e);
                nodes.insert(i);
            }
        }
    }
    map<int, int> remap;
    int from = 2;
    for(auto node : nodes) {
        remap[node] = from++;
    }
    g.resize(nodes.size() + 2);
    for(auto pair : pairs) {
        int from = remap[pair.first], to = remap[pair.second];
        add_edge(0, from);
        add_edge(from, to);
        add_edge(to, 1);
    }
    ll flow = 0ll;
    for(;;) {
        used = vector<bool>(nodes.size() + 2, false);
        ll f = dfs(0, 1, INF);
        if(f == 0ll)
            return flow;
        flow += f;
    }

    return -1;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    ll t;
    cin >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, t, a) << endl;
    return 0;
}
#endif