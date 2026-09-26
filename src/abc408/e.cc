#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long w;
};

// BFSで頂点 0 から 頂点 n-1 に到達可能かを判定
bool traverse(const vector<vector<Edge>>& g, long long mask) {
    int n = g.size();
    vector<long long> d(n, INF);
    queue<int> que;

    d[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int node = que.front();
        que.pop();

        for (const auto& edge : g[node]) {
            int succ = edge.to;
            long long w = edge.w;

            // (w & mask) が真の辺、またはすでに到達済み（距離が以下）の場合はスキップ
            if ((w & mask) || (d[succ] <= d[node] + 1)) {
                continue;
            }

            // 終点に到達できたら即座に true を返す
            if (succ == n - 1) {
                return true;
            }

            d[succ] = d[node] + 1;
            que.push(succ);
        }
    }

    return d[n - 1] < INF;
}

// DFSでパスの重みのOR和の最小値を計算
long long dfs(const vector<vector<Edge>>& g, int node, vector<bool>& visited, long long mask) {
    int n = g.size();
    if (node == n - 1) {
        return 0;
    }

    long long res = INF;
    for (const auto& edge : g[node]) {
        int succ = edge.to;
        long long w = edge.w;

        if ((w & mask) || visited[succ]) {
            continue;
        }

        visited[succ] = true;
        res = min(res, w | dfs(g, succ, visited, mask));
        // 注意: 元のPythonコード通り backtrack (visited[succ] = false) は含まれていません
    }

    return res;
}

int main() {
    // 入出力の高速化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<Edge>> g(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--; // 0-indexed に変換
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    long long mask = 0;
    for (int i = 29; i >= 0; --i) {
        if (traverse(g, mask | (1LL << i))) {
            mask |= (1LL << i);
        }
    }

    vector<bool> visited(n, false);
    cout << dfs(g, 0, visited, mask) << "\n";

    return 0;
}
