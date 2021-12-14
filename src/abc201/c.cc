#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    ll ans = 0ll;
    vector<bool> must(10, false);
    vector<bool> must_not(10, false);
    for(int i = 0; i < 10; i++) {
        if(s[i] == 'o') {
            must[i] = true;
        } else if(s[i] == 'x') {
            must_not[i] = true;
        }
    }

    for(int a = 0; a < 10; a++) {
        for(int b = 0; b < 10; b++) {
            for(int c = 0; c < 10; c++) {
                for(int d = 0; d < 10; d++) {
                    vector<bool> p_must(10, false);
                    p_must[a] = p_must[b] = p_must[c] = p_must[d] = true;
                    bool ok = true;
                    for(int i = 0; i < 10; i++) {
                        if(must[i] && !p_must[i]) {
                            ok = false;
                        }
                        if(must_not[i] &&
                           (a == i || b == i || c == i || d == i)) {
                            ok = false;
                        }
                    }
                    if(ok) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
#endif