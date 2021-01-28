#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc_depth(ll n) {
    ll depth = 0ll;
    while(true) {
        if(1ll << depth <= n && n < 1ll << (depth + 1ll))
            return depth;
        depth++;
    }
    return depth;
}
string solve(ll n) {
    ll dep = calc_depth(n), x = 1ll;
    bool takahashi = true;
    while(true) {
        if(dep % 2ll == 0ll) {
            if(takahashi) {
                x = (2 * x + 1);
                if(x > n) {
                    return "Aoki";
                }
            } else {
                x = (2 * x);
                if(x > n) {
                    return "Takahashi";
                }
            }
        } else {
            if(takahashi) {
                x = (2 * x);
                if(x > n) {
                    return "Aoki";
                }
            } else {
                x = (2 * x + 1);
                if(x > n) {
                    return "Takahashi";
                }
            }
        }
        takahashi = !takahashi;
    }
}
/*
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
*/