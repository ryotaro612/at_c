#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

typedef pair<int, int> P;

const int INF = 100010;

#ifdef ONLINE_JUDGE
main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n - 1), b(n - 1), c(q), d(q);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    for(int i = 0; i < q; i++) {
        cin >> c[i] >> d[i];
        c[i]--;
        d[i]--;
    }
    vector<vector<int>> g(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<int> h(n, INF);
    h[0] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({0, 0});
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        if(h[p.second] < p.first)
            continue;
        for(int i = 0; i < (int)g[p.second].size(); i++) {
            int e = g[p.second][i];
            if(h[p.second] + 1 < h[e]) {
                h[e] = h[p.second] + 1;
                que.push({h[e], e});
            }
        }
    }
    for(int i = 0; i < q; i++) {
        if(h[c[i]] % 2 == h[d[i]] % 2) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
    return 0;
}
#endif