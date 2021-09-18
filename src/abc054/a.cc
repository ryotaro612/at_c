#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifndef _debug
int main() {
    string s;
    cin >> s;
    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';

    rep(i, 2) {
        rep(j, 2) {
            rep(k, 2) {
                int test = a;
                if(i)
                    test += b;
                else
                    test -= b;
                if(j)
                    test += c;
                else
                    test -= c;
                if(k)
                    test += d;
                else
                    test -= d;
                if(test == 7) {
                    string ans = to_string(a);
                    if(i)
                        ans += "+";
                    else
                        ans += "-";
                    ans += to_string(b);
                    if(j)
                        ans += "+";
                    else
                        ans += "-";
                    ans += to_string(c);
                    if(k)
                        ans += "+";
                    else
                        ans += "-";
                    ans += to_string(d) + "=7";
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
#endif