#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<ll> solve(int n, vector<ll> &a, vector<ll> &b) {
    unordered_set<ll> day_set;
    rep(i, n) {
        day_set.insert(a[i]);
        day_set.insert(a[i] + b[i]);
    }
    vector<ll> days(day_set.begin(), day_set.end());
    sort(days.begin(), days.end());
    unordered_map<ll, int> day_map;
    rep(i, days.size()) { day_map[days[i]] = i; }
    vector<int> imos(days.size(), 0);
    rep(i, n) {
        imos[day_map[a[i]]] += 1;
        imos[day_map[a[i] + b[i]]] -= 1;
    }
    rep(i, days.size()) {
        if(i > 0)
            imos[i] += imos[i - 1];
    }
    vector<ll> ans(n, 0ll);
    rep(i, days.size() - 1) {
        // days[i]は日付
        if(imos[i] > 0) {
            ans[imos[i] - 1] += days[i + 1] - days[i];
        }
    }
    return ans;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<ll> res = solve(n, a, b);
    rep(i, n) {
        cout << res[i];
        if(i == n - 1)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}
#endif