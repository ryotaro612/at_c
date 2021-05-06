#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow10(ll x) {
    ll ans = 1ll;
    for(int i = 0; i < x; i++)
        ans *= 10ll;
    return ans;
}
static const ll pow9 = 1000000000ll;
vector<ll> solve(ll s) {
    ll x, y;
    if(s % pow9 == 0)
        x = s / pow9;
    else
        x = s / pow9 + 1ll;
    y = pow9 * x - s;
    return {0, 0, 1, pow9, x, y};
}

#ifndef _LOCAL
int main() {
    ll s;
    cin >> s;

    vector<ll> ans = solve(s);
    for(int i = 0; i < 5; i++)
        cout << ans[i] << " ";
    cout << ans[5] << endl;
    return 0;
}
#endif