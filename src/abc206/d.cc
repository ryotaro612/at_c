#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> par;

void init(int n) {
    par.resize(n + 1);
    for(int i = 0; i <= n; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void unite(int a, int b) {
    int g_a = find(a), g_b = find(b);
    if(g_a == g_b)
        return;
    par[g_a] = g_b;
}

bool is_same(int a, int b) { return find(a) == find(b); }

int solve(int n, vector<int> a) {
    int mx = -1;
    for(auto aa : a)
        mx = max(aa, mx);
    init(mx);

    int ans = 0;
    for(int i = 0; i < n / 2; i++) {
        if(find(a[i]) == find(a[n - 1 - i])) {
            continue;
        }
        ans++;
        unite(a[i], a[n - 1 - i]);
    }

    return ans;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
    return 0;
}
#endif