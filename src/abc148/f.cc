#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<int> measure_dist(vector<vector<int>> g, int u) {
    int n = g.size();
    const int INF = 10000000;
    vector<int> d(n, INF);
    queue<pair<int, int>> que;
    d[u] = 0;
    que.push({d[u], u});
    while(!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        int point = p.second, dist = p.first;
        if(d[point] < dist)
            continue;
        rep(i, g[point].size()) {
            int neighbor = g[point][i];
            if(dist + 1 < d[neighbor]) {
                d[neighbor] = dist + 1;
                que.push({d[neighbor], neighbor});
            }
        }
    }
    return d;
}

int find_goal(vector<int> &aoki_dists, vector<int> &takahashi_dists) {
    int n = aoki_dists.size();
    int dist = 0;
    int res;
    rep(i, n) {
        if(takahashi_dists[i] < aoki_dists[i]) {
            if(dist < aoki_dists[i]) {
                dist = aoki_dists[i];
                res = i;
            }
        }
    }
    return res;
}
bool find_path(vector<vector<int>> &g, int current, int prev, int goal,
               vector<int> &path) {
    path.push_back(current);
    if(current == goal) {
        return true;
    }
    rep(i, g[current].size()) {
        if(g[current][i] == prev)
            continue;
        if(find_path(g, g[current][i], current, goal, path)) {
            return true;
        } else {
            path.pop_back();
        }
    }
    return false;
}
/**
 * v 青木くん
 * u 高橋くん
 */
int solve(int n, int u, int v, vector<int> &a, vector<int> &b) {
    u--;
    v--;
    rep(i, n - 1) {
        a[i]--;
        b[i]--;
    }
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<int> aoki_dists = measure_dist(g, v);
    vector<int> takahashi_dists = measure_dist(g, u);
    int goal = find_goal(aoki_dists, takahashi_dists);
    vector<int> aoki_path, takahashi_path;
    find_path(g, v, v, goal, aoki_path);
    find_path(g, u, u, goal, takahashi_path);
    int takahashi_index = 0, takahashi_pos = takahashi_path[0], aoki = 0;
    while(true) {
        if(takahashi_index < (int)takahashi_path.size() - 1) {
            takahashi_index++;
            takahashi_pos = takahashi_path[takahashi_index];
        } else {
            takahashi_index--;
            takahashi_pos = aoki_path[aoki_path.size() - 2];
        }
        if(aoki_path[aoki] == takahashi_pos)
            return aoki;
        aoki++;
        if(aoki_path[aoki] == takahashi_pos)
            return aoki;
    }
    assert(false);
    return -1;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, u, v;
    cin n >> u >> v;
    vector<int> a(n - 1), b(n - 1);
    rep(i, n - 1) cin >> a[i] >> b[i];
    cout << solve(n, u, v, a, b) << endl;
    return 0;
}
#endif