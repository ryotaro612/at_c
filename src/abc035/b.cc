#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(string s, ll t) {
    ll x = 0ll, y = 0ll, unknown = 0ll;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '?') {
            unknown++;
        } else if(s[i] == 'L') {
            x -= 1;
        } else if(s[i] == 'R') {
            x += 1;
        } else if(s[i] == 'U') {
            y += 1;
        } else if(s[i] == 'D') {
            y -= 1;
        }
    }
    if(t == 1ll) { // 最大値
        return abs(x) + abs(y) + unknown;
    } else { // 最小値
        if((abs(x) + abs(y)) >= unknown) {
            return abs(x) + abs(y) - unknown;
        }
        if((unknown - abs(x) - abs(y)) % 2ll == 1ll) {
            return 1ll;
        } else {
            return 0ll;
        }
    }
}
/*
int main() {
    string s;
    ll t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
}
*/