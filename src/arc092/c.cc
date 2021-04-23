#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 1 << 20;
struct edge {
    int to;
    int cap;
    int rev;
};

void add_edge(vector<vector<edge>> &g, int from, int to, int cap) {
    g[from].push_back({to, cap, (int)g[to].size()});
    g[to].push_back({from, 0, (int)g[from].size() - 1});
}

/*
 * f is request
 */
int dfs(vector<vector<edge>> &g, vector<bool> &used, int v, int t, int f) {
    if(v == t)
        return f;
    used[v] = true;
    for(int i = 0; i < (int)g[v].size(); i++) {
        edge &e = g[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(g, used, e.to, t, min(e.cap, f));
            if(d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int solve(int n, vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
    int num_vertex = 2 + 2 * n;
    vector<vector<edge>> g(num_vertex);
    // start: 0
    // red: 1 - n
    // blue n+1 - 2*n
    // end: 2*n + 1
    for(int i = 1; i <= n; i++) {
        add_edge(g, 0, i, 1);
        add_edge(g, n + i, 2 * n + 1, 1);
    }
    for(int rd = 1; rd <= n; rd++) {
        for(int bd = n + 1; bd <= 2 * n; bd++) {
            if(a[rd - 1] < c[bd - n - 1] && b[rd - 1] < d[bd - n - 1]) {
                add_edge(g, rd, bd, 1);
            }
        }
    }
    int res = 0;
    while(true) {
        vector<bool> used(num_vertex, false);
        int f = dfs(g, used, 0, num_vertex - 1, INF);
        if(f == 0) {
            return res;
        }
        res += f;
    }
    // unreachable.
    return -1;
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i] >> d[i];
    }
    cout << solve(n, a, b, c, d);
}
*/