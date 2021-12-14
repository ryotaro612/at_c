#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

vector<int> par;

int find_root(int i) {
    if(par[i] < 0)
        return i;
    return par[i] = find_root(par[i]);
}

void init(int n) { par = vector<int>(n, -1); }

bool same_group(int a, int b) { return find_root(a) == find_root(b); }

void unite(int a, int b) {
    if(same_group(a, b))
        return;
    int root_a = find_root(a);
    int root_b = find_root(b);
    if(par[root_a] < par[root_b]) {
        par[root_a] += par[root_b];
        par[root_b] = root_a;
    } else {
        par[root_b] += par[root_a];
        par[root_a] = root_b;
    }
}

string solve(int n, int m, vector<int> &a, vector<int> &b) {
    vector<int> count(n, 0);
    rep(i, m) {
        count[--a[i]]++;
        count[--b[i]]++;
        if(count[a[i]] > 2 || count[b[i]] > 2)
            return "No";
    }
    init(n);
    rep(i, m) {
        if(same_group(a[i], b[i]))
            return "No";
        unite(a[i], b[i]);
    }

    return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) { cin >> a[i] >> b[i]; }
    cout << solve(n, m, a, b) << endl;
    return 0;
}
#endif