#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<ll, int>>> build_graph(int n, vector<ll> x, vector<ll> y) {
    vector<vector<pair<ll, int>>> edges(n, vector<pair<ll, int>>());

    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) { return x[i] < x[j]; });
    for(int i = 0; i < n - 1; i++) {
        int id = ids[i];
        int next_id = ids[i + 1];
        edges[id].push_back(make_pair(abs(x[id] - x[next_id]), next_id));
        edges[next_id].push_back(make_pair(abs(x[id] - x[next_id]), id));
    }
    sort(ids.begin(), ids.end(), [&](int i, int j) { return y[i] < y[j]; });
    for(int i = 0; i < n - 1; i++) {
        int id = ids[i];
        int next_id = ids[i + 1];
        edges[id].push_back(make_pair(abs(y[id] - y[next_id]), next_id));
        edges[next_id].push_back(make_pair(abs(y[id] - y[next_id]), id));
    }
    return edges;
}

ll solve(int n, vector<ll> x, vector<ll> y) {

    vector<vector<pair<ll, int>>> edges = build_graph(n, x, y);

    vector<bool> used(n, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        que;

    for(int i = 0; i < (int)edges[0].size(); i++) {
        que.push(edges[0][i]);
    }

    used[0] = true;
    ll res = 0;
    while(!que.empty()) {
        pair<ll, int> v = que.top();
        que.pop();
        if(used[v.second])
            continue;
        used[v.second] = true;
        for(int i = 0; i < (int)edges[v.second].size(); i++) {
            auto edge = edges[v.second][i];
            if(!used[edge.second]) {
                que.push(edge);
            }
        }
        res += v.first;
    }

    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, x, y);
}
*/