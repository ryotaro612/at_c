#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k, vector<ll> s) {
    ll res = 0ll, sum = s[0];
    int begin = 0, end = 1;
    // s[0]がk以上のときを考える
    for(;;) {
        if(sum > k) {
            while(begin < end) {
                sum /= s[begin];
                begin++;
                if(sum < k) {
                    res = max(sum, res);
                    break;
                }
            }
            if(end > n + 1)
                break;
            if(begin == end)
                end++;
        } else {
        }
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
    cout << solve(n, k, s) << end;
    return 0;
}
*/