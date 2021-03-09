#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(ll a, ll b, ll c, ll d) {
    ll temp = 3;
    for(int i = 0; i < 36; i++) {
        temp *= 3;
    }
    vector<ll> cookies = {a, b, c, d};
    for(int i = 1; i < 1 << 4; i++) {
        ll noteat = 0ll;
        ll eat = 0ll;
        for(int j = 0; j < 4; j++) {
            if(i & (1 << j))
                noteat += cookies[j];
            else
                eat += cookies[j];
        }
        if(noteat == eat)
            return "Yes";
    }
    return "No";
}

#ifndef _LOCAL
int main() {
    ll a, b, c, d;

    cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << endl;
}
#endif