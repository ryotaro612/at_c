#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, ll c, vector<ll> av, vector<ll> bv, vector<ll> cv) {
    map<ll, ll> acc;
    for(int i = 0; i < n; i++) {
        acc[av[i]] += cv[i];
        acc[bv[i] + 1] -= cv[i];
    }
    ll res = 0, current = 0;
    for(auto iter = acc.begin(); iter != acc.end(); ++iter) {
        pair<ll, ll> entry = *iter;
        if(iter == acc.begin()) {
            current = entry.second;
            continue;
        }
        pair<ll, ll> prev_entry = *prev(iter);
        ll days = entry.first - prev_entry.first;
        ll delta = min(current, c) * days;
        res += delta;
        current = max(current + entry.second, 0LL);
    }
    return res;
}
/*
int main() {
    int n, c;
    cin >> n >> c;
    vector<ll> av(n), bv(n), cv(n);
    for(int i = 0; i < n; i++) {
        cin >> av[i] >> bv[i] >> cv[i];
    }
    cout << solve(n, c, av, bv, cv);
    return 0;
}
*/