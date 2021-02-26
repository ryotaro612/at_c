#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const static int INF = 1000000;

typedef pair<int, int> P;

vector<int> djkstra(vector<vector<int>> edges) {
    vector<int> d((int)edges.size(), INF);
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, 0));
    d[0] = 0;
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        if(d[p.second] < p.first)
            continue;
        for(int i = 0; i < (int)edges[p.second].size(); i++) {
            int next_node = edges[p.second][i];
            if(d[p.second] + 1 < d[next_node]) {
                d[next_node] = d[p.second] + 1;
                que.push(P(d[next_node], next_node));
            }
        }
    }
    return d;
}

bool contains_bridges(vector<vector<int>> edges) {
    vector<int> d = djkstra(edges);
    for(auto dd : d) {
        if(dd == INF)
            return true;
    }

    return false;
}

int solve(int n, int m, vector<int> a, vector<int> b) {
    int res = 0;
    for(int i = 0; i < m; i++) {
        vector<vector<int>> edges(n);
        for(int j = 0; j < m; j++) {
            if(j != i) {
                edges[a[j] - 1].push_back(b[j] - 1);
                edges[b[j] - 1].push_back(a[j] - 1);
            }
        }
        res += contains_bridges(edges);
    }

    return res;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, m, a, b) << endl;
}
#endif