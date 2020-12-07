#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const static ll INF = 922337203685;

vector<ll> dijkstra(int n, ll start, vector<vector<int>> &edges) {
    vector<ll> d(n, INF);
    priority_queue<ll, vector<ll>, greater<ll>> que;
    que.push(start);
    d[start] = 0;
    while(!que.empty()) {
        ll to = que.top();
        que.pop();
        for(int i = 0; (long unsigned long)i < edges[to].size(); i++) {
            ll neighbor = edges[to][i];
            if(d[neighbor] > d[to] + 1) {
                d[neighbor] = d[to] + 1;
                que.push(neighbor);
            }
        }
    }
    return d;
}

string solve(int n, vector<int> a, vector<int> b) {
    vector<vector<int>> edges(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        edges[a[i] - 1].push_back(b[i] - 1);
        edges[b[i] - 1].push_back(a[i] - 1);
    }
    vector<ll> da = dijkstra(n, 0, edges);
    vector<ll> db = dijkstra(n, n - 1, edges);

    ll count = 0;
    for(int i = 0; i < n; i++) {
        if(da[i] <= db[i]) {
            count++;
        }
    }
    return count > n - count ? "Fennec" : "Snuke";
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1), b(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, a, b);
}
*/