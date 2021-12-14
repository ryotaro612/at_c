#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> consumed;
vector<set<int>> v;

void dfs(int i) {

    consumed[i] = true;
    for(auto e : v[i]) {
        if(!consumed[e])
            dfs(e);
    }
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i];

    for(int i = 0; i < m; i++) {
        a[i]--;
        b[i]--;
    }
    v = vector<set<int>>(n, set<int>());
    for(int i = 0; i < m; i++) {
        v[a[i]].insert(b[i]);
    }
    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        consumed = vector<bool>(n, false);
        dfs(i);
        for(int j = 0; j < n; j++)
            if(consumed[j])
                ans++;
        /*
        cout << i << " -> ";
        for(int j = 0; j < n; j++)
            if(consumed[j])
                cout << j << " ";
        cout << endl;
        */
    }
    cout << ans << endl;
    return 0;
}
#endif