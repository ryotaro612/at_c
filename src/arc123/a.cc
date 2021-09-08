#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<ll> a) {

    if(a[0] < a[1] && a[1] < a[2]) {
        if(a[1] - a[0] == a[2] - a[1])
            return 0ll;
        else if(a[1] - a[0] > a[2] - a[1]) {
            return (a[1] - a[0]) - (a[2] - a[1]);
        } else {
            ll offset = (a[2] - a[0]) % 2ll == 1ll ? 1ll : 0ll;
            a[2] += offset;
            return offset + (a[2] - (a[2] - a[0]) / 2ll - a[1]);
        }
    }
    if(a[0] == a[1] && a[2] == a[1])
        return 0ll;
    if(a[0] == a[1]) {
        if(a[0] > a[2]) {
            return 1ll + solve({a[2], a[1], a[0] + 1ll});
        } else { // a[0] < a[2]
            return 1ll + solve({a[0], a[1] + 1, a[2]});
        }
    } else if(a[1] == a[2]) {
        return solve({a[2], a[1], a[0]});
    } else if(a[0] == a[2]) {
        if(a[0] < a[1]) {
            return (a[1] - a[0]) * 2ll;
        } else {
            return a[0] - a[1];
        }
    }
    if(a[0] == *max_element(a.begin(), a.end())) {
        if(a[1] > a[2]) {
            return solve({a[2], a[1], a[0]});
        } else {
            return a[2] - a[1] + solve({a[2], a[2], a[0]});
        }
    }
    if(a[1] == *max_element(a.begin(), a.end())) {
        return a[1] - a[0] + a[1] - a[2];
    }
    return a[0] - a[1] + solve({a[0], a[0], a[2]});
}

#ifndef _debug
int main() {
    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];
    cout << solve(a) << endl;
    return 0;
}
#endif