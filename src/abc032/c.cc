#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k, vector<ll> s) {
    for(int i = 0; i < n; i++) {
        if(s[i] == 0)
            return n;
    }
    ll from = 0, to = 0, sum = 0, res = 0;
    for(;;) {
        if(from == to)
            sum = 0;
        // cout << "top: " << from << " - " << to << " sum: " << sum << endl;
        while(to < n && (from == to ? s[to] : sum * s[to]) <= k) {
            if(from == to) {
                sum = s[to];
            } else {
                sum *= s[to];
            }
            to++;
            // cout << "right: " << from << " - " << to << " sum: " << sum <<
            // endl;
        }
        if(sum > k || to == n) {
            break;
        }
        res = max(res, to - from);
        sum /= s[from];
        from++;
    }
    return res;
}
/*
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> s(n);
    for(ll i = 0ll; i < n; i++) {
        cin >> s[i];
    }
    cout << solve(n, k, s) << endl;
    return 0;
}
*/