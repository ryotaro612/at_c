#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(string s) {
    ll n = (ll)s.size();
    if(n == 1) {
        return 1;
    }
    ll res = n;
    for(ll i = 0; i < n - 1; i++) {
        if(s[i] != s[i + 1]) {
            res = min(max(i + 1, n - (i + 1)), res);
        }
    }
    return res;
}
/*
int main() {
    string s;
    cin >> s;
    cout << solve(s);
}
*/