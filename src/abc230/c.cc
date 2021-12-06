#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<string> solve(ll n, ll a, ll b, ll p, ll q, ll r, ll s) {
    vector<string> res(q - p + 1, string(s - r + 1, '.'));
    for(ll i = p; i <= q; i++) {
        for(ll j = r; j <= s; j++) {
            if(abs(a - i) != abs(b - j))
                continue;
            if((i >= a && j >= b) || (i < a && j < b)) {
                if(a + max(1ll - a, 1ll - b) <= i &&
                   i <= a + min(n - a, n - b)) {
                    res[i - p][j - r] = '#';
                }
            } else {
                if(a + max(1ll - a, b - n) <= i &&
                   i <= a + min(n - a, b - 1ll)) {
                    res[i - p][j - r] = '#';
                }
            }
        }
    }
    return res;
}

#ifndef _debug
int main() {
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    vector<string> res = solve(n, a, b, p, q, r, s);
    for(auto s : res)
        cout << s << endl;
    return 0;
}
#endif