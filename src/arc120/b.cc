#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll MOD = 998244353ll;

#ifndef _LOCAL
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++)
        cin >> s[i];
    ll ans = 1ll;
    for(int i = 0; i < h; i++) {
        set<char> colors;
        // k は行 jは列
        for(int j = 0, k = i; k >= 0 && j < w; j++, k--) {
            if(s[k][j] != '.')
                colors.insert(s[k][j]);
        }
        switch((int)colors.size()) {
        case 0:
            ans *= 2;
            ans %= MOD;
            break;
        case 1:
            break;
        default:
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 1; i < w; i++) {
        set<char> colors;
        // aは行 bは列
        for(int a = h - 1, b = i; a >= 0 && b < w; a--, b++) {
            if(s[a][b] != '.')
                colors.insert(s[a][b]);
        }
        switch((int)colors.size()) {
        case 0:
            ans *= 2;
            ans %= MOD;
            break;
        case 1:
            break;
        default:
            cout << 0 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}
#endif
