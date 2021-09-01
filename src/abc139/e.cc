#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void rec_dag(vector<vector<int>> &g, int node, vector<bool> &seen,
             vector<int> &dep, int &time, vector<int> &order) {
    seen[node] = true;
    for(int i = 0; i < (int)g[node].size(); i++) {
        if(!seen[g[node][i]])
            rec_dag(g, g[node][i], seen, dep, time, order);
    }
    order.push_back(node);
    dep[node] = time++;
}

bool is_dag(vector<vector<int>> &g, vector<int> &order) {
    int n = g.size();
    vector<bool> seen(n);
    vector<int> dep(n);
    int time = 0;
    for(int i = 0; i < n; i++) {
        if(!seen[i])
            rec_dag(g, i, seen, dep, time, order);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            if(dep[i] <= dep[g[i][j]])
                return false;
        }
    }
    reverse(order.begin(), order.end());
    return true;
}

int solve(int n, vector<vector<int>> a) {
    vector<vector<int>> enc(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            a[i][j]--;
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            enc[j][i] = enc[i][j] = count++;

    vector<vector<int>> g(n * (n - 1) / 2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 2; j++) {
            g[enc[i][a[i][j]]].push_back(enc[i][a[i][j + 1]]);
        }
    }
    vector<int> order;
    if(!is_dag(g, order))
        return -1;

    vector<int> dist(n * (n - 1) / 2, 1);
    for(int i = (int)order.size() - 1; i >= 0; i--) {
        if(g[order[i]].size() == 0)
            dist[order[i]] = 1;
        else {
            for(int j = 0; j < g[order[i]].size(); j++) {
                dist[order[i]] = max(dist[g[order[i]][j]] + 1, dist[order[i]]);
            }
        }
    }
    return *max_element(dist.begin(), dist.end());
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            cin >> a[i][j];
    cout << solve(n, a) << endl;
    return 0;
}
#endif