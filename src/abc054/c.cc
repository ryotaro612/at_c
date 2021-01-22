#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs(int from, vector<bool> &used, vector<vector<int>> &nodes) {
    bool all_used = true;
    for(auto i : used) {
        if(!i) {
            all_used = false;
            break;
        }
    }
    if(all_used) {
        return 1;
    }
    int count = 0;
    for(int i = 0; i < (int)nodes[from].size(); i++) {
        int node = nodes[from][i];
        if(!used[node]) {
            used[node] = true;
            count += dfs(node, used, nodes);
            used[node] = false;
        }
    }
    return count;
}

int solve(int n, int m, vector<int> a, vector<int> b) {
    vector<vector<int>> nodes(n);
    for(int i = 0; i < m; i++) {
        nodes[a[i] - 1].push_back(b[i] - 1);
        nodes[b[i] - 1].push_back(a[i] - 1);
    }
    vector<bool> used(n, false);
    used[0] = true;
    return dfs(0, used, nodes);
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, m, a, b);
}
*/