#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ten(int i) {
    ll ans = 1ll;
    for(int j = 0; j < i - 1; j++)
        ans *= 10ll;
    return ans;
}

ll count(string s, int offset) {
    ll a = 1ll, ans = 0ll;
    for(int i = 0; i < offset; i++) {
        ll digit = s[i] - '0';
        ans += digit * a;
        a *= 10ll;
    }
    return ans + 1ll;
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll ans = 0ll;
    for(int i = 0; i < (int)s.size(); i++) {
        for(int j = i + 1; j < (int)s.size(); j++) {
            ll d = s[j] - '0';
            ans += ten(j) * d;
        }
        ll digit = s[i] - '0';
        if(digit > 1ll)
            ans += ten(i + 1);
        else if(digit == 1ll)
            ans += count(s, i);
    }
    cout << ans << endl;
    return 0;
}
#endif