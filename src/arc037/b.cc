#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> par(101);

int find(int v) {
    if(par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

void unite(int a, int b) {
    int pa = find(a), pb = find(b);
    par[pb] = pa;
}

bool same_group(int a, int b) { return find(a) == find(b); }

int solve(int n, int m, vector<int> u, vector<int> v) {
    vector<int> close(n, false);
    for(int i = 0; i < n; i++)
        par[i] = i;
    for(int i = 0; i < m; i++) {
        u[i]--;
        v[i]--;
    }

    for(int i = 0; i < m; i++) {
        if(same_group(u[i], v[i])) {
            close[u[i]] = close[v[i]] = true;
        } else {
            unite(u[i], v[i]);
        }
    }
    set<int> groups, closed_groups;
    for(int i = 0; i < n; i++) {
        groups.insert(find(i));
        if(close[i]) {
            closed_groups.insert(find(i));
        }
    }
    return (int)groups.size() - (int)closed_groups.size();
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    for(int i = 0; i < m; i++)
        cin >> u[i] >> v[i];

    cout << solve(n, m, u, v) << endl;
    return 0;
}
#endif