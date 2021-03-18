#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool same_cost(int m, vector<ll> &c, vector<ll> &d) {
    ll sum_c = 0ll, sum_d = 0ll;
    for(int i = 0; i < m; i++) {
        sum_c += c[i];
        sum_d += d[i];
    }
    return sum_c == sum_d;
}

string solve(int n, int m, vector<ll> a, vector<ll> b, vector<ll> c,
             vector<ll> d) {
    if(!same_cost(n, a, b))
        return "No";
    vector<vector<int>> edges(n);
    cout << "!!!foobar!!!" << endl;
    for(int i = 0; i < m; i++) {
        edges[c[i] - 1].push_back(d[i] - 1);
        edges[d[i] - 1].push_back(c[i] - 1);
    }
    vector<bool> used(n, false);
    queue<int> que;
    if(m > 0) {
        que.push(c[0] - 1);
    }
    cout << "foobar!!!" << endl;
    while(!que.empty()) {
        int node = que.front();
        que.pop();
        used[node] = true;
        for(int i = 0; i < (int)edges[node].size(); i++) {
            if(!used[edges[node][i]])
                que.push(edges[node][i]);
        }
    }
    for(auto u : used) {
        if(!u)
            return "No";
    }
    return "Yes";
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
    cout << solve(n, m, a, b, c, d) << endl;
    return 0;
}
#endif