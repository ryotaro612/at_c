#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(string &s) {
    reverse(s.begin(), s.end());
    // cout << s << endl;
    ll n = (ll)s.size(), ans = 0ll, acc = 0ll;

    for(ll i = 0ll; i < n; i++) {
        ll c = s[i] - '0';
        if((c + acc) <= 4ll) {
            //    cout << s[i] << " -> " << (c + acc) << endl;
            ans += (c + acc);
            acc = 0ll;
        } else if(c + acc == 5ll) {
            if(i + 1 < n && s[i + 1] - '0' >= 5) {
                ans += ((10ll - acc) - c);
                acc = 1ll;
            } else {
                ans += (c + acc);
                acc = 0ll;
            }
        } else {
            ans += ((10ll - acc) - c);
            // cout << s[i] << " -> " << ((10ll - acc) - c) << endl;
            acc = 1ll;
        }
    }
    ans += acc;

    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    string n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}
#endif