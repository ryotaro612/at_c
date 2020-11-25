#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll k) {
    ll mx = 1 << 29;
    vector<ll> dist(k, mx);
    dist[1] = 0;
    // vector<vector<pair<ll, ll>>> edges(k - 1, vector<pair<ll, ll>>());

    deque<ll> que;
    que.push_back(1);
    while(!que.empty()) {
        ll node = que.front();
        que.pop_front();
        ll n0 = (node * 10) % k;
        if(dist[n0] > dist[node]) {
            dist[n0] = dist[node];
            que.push_front(n0);
        }
        ll n1 = (node + 1) % k;
        if(dist[n1] > dist[node] + 1) {
            dist[n1] = dist[node] + 1;
            que.push_back(n1);
        }
    }
    return dist[0] + 1;
}
/*
int main() {
    ll k;
    cin >> k;
    cout << solve(k);
}
*/