#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll h, vector<ll> a, vector<ll> b) {
    vector<pair<ll, bool>> ab;
    for(auto aa : a) {
        ab.push_back(make_pair(aa, true));
    }
    for(auto bb : b) {
        ab.push_back(make_pair(bb, false));
    }
    sort(ab.begin(), ab.end(),
         [](const pair<ll, bool> &x, const pair<ll, bool> &y) {
             return x.first > y.first;
         });

    ll hh = h;
    ll idx = 0;
    while(!ab[idx].second) {
        hh -= ab[idx].first;
        idx++;
        if(hh <= 0) {
            return idx;
        }
    }
    if(hh % ab[idx].first == 0) {
        return idx + ll(hh / ab[idx].first);
    }
    return idx + ll(hh / ab[idx].first) + 1LL;
}
/*
int main() {
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, h, a, b);
}
*/