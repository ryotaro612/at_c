#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k, vector<ll> s) {
    ll sum, res, begin, end;
    for(ll i = 0; i < n; i++) {
        if(s[i] <= k) {
            begin = i;
            end = begin + 1;
            sum = s[begin];
            res = 1;
            break;
        }
        if(i == n - 1)
            return 0;
    }

    for(;;) {
        if(end != n && sum * s[end] < k) {
            sum *= s[end];
            end++;
            res = max(end - begin, res);
            if(end == n) {
                break;
            }
        } else { // end == n || s[end] >= k
            if(begin + 1 < end) {
                sum /= s[begin];
                begin++;
            } else { // begin + 1>= end
                sum /= s[begin];
                begin++;
                end++;
            }
        }
    }
    return end - begin;
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