#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll MOD = 1000000007ll;

#ifndef _LOCAL
int main() {
    ll n;
    string s;
    cin >> n >> s;

    vector<int> a(26, 0);
    for(auto c : s) {
        a[c - 'a']++;
    }
    ll ans = 1ll;
    for(auto aa : a) {
        ans *= (aa + 1ll);
        ans %= MOD;
    }
    ans--;
    cout << ans << endl;
    return 0;
}
#endif