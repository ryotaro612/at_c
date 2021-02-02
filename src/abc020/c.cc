#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
    ll to, cost;
};

ll const INF = 100000000000ll;

ll calc_cost(char node, ll black) { return node == '#' ? black : 1; }

ll shortest_path_search(int h, int w, ll black, vector<string> s) {
    vector<vector<edge>> edges(h * w);
    int start = -1, goal = -1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int index = w * i + j;
            if(s[i][j] == 'S')
                start = index;
            if(s[i][j] == 'G')
                goal = index;
            if(i != 0) {
                edges[index].push_back(
                    {w * (i - 1) + j, calc_cost(s[i - 1][j], black)});
            }
            if(j != w - 1) {
                edges[index].push_back(
                    {w * i + j + 1, calc_cost(s[i][j + 1], black)});
            }
            if(i != h - 1) {
                edges[index].push_back(
                    {w * (i + 1) + j, calc_cost(s[i + 1][j], black)});
            }
            if(j != 0) {
                edges[index].push_back(
                    {w * i + (j - 1), calc_cost(s[i][j - 1], black)});
            }
        }
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        que;
    vector<ll> d(h * w, INF);
    d[start] = 0ll;
    que.push(make_pair(0ll, start));
    while(!que.empty()) {
        pair<ll, int> p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) {
            continue;
        }
        for(int i = 0; i < (int)edges[v].size(); i++) {
            edge e = edges[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
    return d[goal];
}

ll solve(int h, int w, ll t, vector<string> s) {
    ll lb = 0, ub = t + 1ll;

    while(ub - lb > 1ll) {
        ll mid = (lb + ub) / 2ll;
        ll cost = shortest_path_search(h, w, mid, s);
        if(cost <= t) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    return lb;
}
/*
int main() {
    int h, w;
    cin >> h >> w;
    ll t;
    cin >> t;
    vector<string> s(h);
    for(int i = 0; i < h; i++) {
        cin >> s[i];
    }
    cout << solve(h, w, t, s) << endl;
}
*/