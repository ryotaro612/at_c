#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const ll INF = 10000000000ll;

void count_subtree_nums(int index, vector<vector<int>> &g,
                        vector<ll> &subtree_nums) {
    subtree_nums[index] = 1ll;
    rep(i, g[index].size()) {
        int node = g[index][i];
        if(subtree_nums[node] < 0) {
            count_subtree_nums(node, g, subtree_nums);
            subtree_nums[index] += subtree_nums[node];
        }
    }
}

void count_cost(int index, vector<ll> &cost, vector<vector<int>> &g,
                vector<ll> &subtree_nums) {
    rep(i, g[index].size()) {
        int node = g[index][i];
        if(cost[node] >= 0)
            continue;

        cost[node] = cost[index] - subtree_nums[node] +
                     (subtree_nums[0] - subtree_nums[node]);
        count_cost(node, cost, g, subtree_nums);
    }
}

vector<ll> solve(int n, vector<ll> &u, vector<ll> &v) {
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        g[--u[i]].push_back(--v[i]);
        g[v[i]].push_back(u[i]);
    }
    vector<ll> d(n, INF);
    d[0] = 0ll;
    queue<pair<ll, int>> que;
    que.push({0ll, 0});
    while(!que.empty()) {
        ll cost = que.front().first;
        int node = que.front().second;
        que.pop();
        if(d[node] < cost)
            continue;
        rep(i, g[node].size()) {
            int neighbor = g[node][i];
            if(d[neighbor] > cost + 1ll) {
                d[neighbor] = cost + 1ll;
                que.push({d[neighbor], neighbor});
            }
        }
    }
    vector<ll> subtree_nums(n, -1ll);
    count_subtree_nums(0, g, subtree_nums);
    vector<ll> ans(n, -1ll);
    ans[0] = 0ll;
    for(auto e : d) {
        ans[0] += e;
    }
    count_cost(0, ans, g, subtree_nums);
    return ans;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> u(n - 1), v(n - 1);
    rep(i, n - 1) cin >> u[i] >> v[i];
    vector<ll> res = solve(n, u, v);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif