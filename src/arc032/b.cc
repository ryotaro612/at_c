#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(int i, vector<int> &par) {
    if(par[i] == i)
        return i;
    return par[i] = find(par[i], par);
}
bool same(int a, int b, vector<int> &par) {
    return find(a, par) == find(b, par);
}

void unite(int a, int b, vector<int> &par) {
    int par_a = find(a, par), par_b = find(b, par);
    par[par_b] = par_a;
}

int solve(int n, int m, vector<int> a, vector<int> b) {
    vector<int> par(n);
    for(int i = 0; i < n; i++)
        par[i] = i;

    for(int i = 0; i < m; i++)
        unite(a[i] - 1, b[i] - 1, par);

    set<int> groups;
    for(int i = 0; i < n; i++)
        groups.insert(find(i, par));

    return groups.size() - 1;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    cout << solve(n, m, a, b) << endl;
    return 0;
}
#endif