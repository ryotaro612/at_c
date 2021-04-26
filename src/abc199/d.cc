#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> par;
void init(int n) {
    par.resize(n);
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
    par[y] = x;
}

bool same(int x, int y) { return find(x) == find(y); }

vector<vector<int>> graph;

ll dfs(int node, vector<int> &color) {
    set<int> neigh;
    for(int i = 0; i < (int)graph[node].size(); i++) {
        neigh.insert(color[graph[node][i]]);
    }
    for(int i=0;i< 3;i++) {
        if(neigh.find(i) == neigh.end()) {
            color[node] = i;
            for(int j=0;j<(int) graph[node].size();j++) {

            }
        }
    }
    /*
    if(neigh.find(-1) == neigh.end()) {
        return 3 - neigh.size();
    }

    if(neigh.find(0) != neigh.end() && neigh.find(1) != neigh.end() &&
       neigh.find(2) != neigh.end()) {
        return 0ll;
    }
    ll res = 0ll;
    for(int i = 0; i < 3; i++) {
        if(neigh.find(i) == neigh.end()) {
            color[node] = i;
            vector<ll> temp;
            for(int j = 0; j < (int)graph[node].size(); j++) {
                if(color[graph[node][j]] == -1) {
                    temp.push_back(dfs(graph[node][j], color));
                }
            }
            ll a = 0;
            if(temp.size() > 0) {
                a = temp[0];
            }
        }
    }
    */
    return res;
}

ll solve(int n, int m, vector<int> a, vector<int> b) {
    init(n);
    graph.resize(n);
    for(int i = 0; i < m; i++) {
        a[i]--;
        b[i]--;
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
        unite(a[i], b[i]);
    }
    set<int> subgraphs;
    for(int i = 0; i < n; i++) {
        subgraphs.insert(find(i));
    }
    vector<ll> temp;
    for(auto entry : subgraphs) {
        vector<int> color(n, -1);
        temp.push_back(dfs(entry, color));
    }
    ll ans = temp[0];
    for(int i = 1; i < (int)temp.size(); i++) {
        ans *= temp[i];
    }
    return ans;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    cout << solve(n, m, a, b) << endl;
}
#endif