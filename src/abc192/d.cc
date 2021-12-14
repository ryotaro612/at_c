#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_num(string x) {
    int res = 0ll;
    for(auto xx : x) {
        res = max(xx - '0', res);
    }
    return res;
}

inline bool check(string s, ll b, ll m) {
    __int128 x = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        x = x * b + s[i] - '0';
        if(x > m)
            return true;
    }
    return false;
}

ll solve(string x, ll m) {
    if((int)x.size() == 1) {
        if(x[0] - '0' > m) {
            return 0ll;
        } else {
            return 1ll;
        }
    }
    ll d = max_num(x);
    if(check(x, d + 1, m)) {
        return 0ll;
    }
    ll lb = d, ub = m + 1;
    while(ub - lb > 1ll) {
        ll mid = (lb + ub) / 2ll;
        // cout << "mid: " << mid << endl;
        if(check(x, mid, m)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    return ub - (d + 1ll);
}

#ifdef ONLINE_JUDGE
int main() {
    string x;
    ll m;
    cin >> x >> m;
    cout << solve(x, m) << endl;
}
#endif