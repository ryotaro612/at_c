#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll INF = 100000000000ll;

ll solve(int n, ll t, vector<ll> a) {
    vector<ll> small(n, INF);

    map<ll, vector<int>> mp;
    mp[a[0]].push_back(0);
    for(int i = 1; i < n; i++) {
        small[i] = min(a[i - 1], small[i - 1]);
        mp[a[i]].push_back(i);
    }
    ll unit = -1ll;
    for(int i = 1; i < n; i++)
        unit = max(unit, a[i] - small[i]);
    assert(unit > 0);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] - small[i] == unit)
            ans++;
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    ll t;
    cin >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, t, a) << endl;
    return 0;
}
#endif