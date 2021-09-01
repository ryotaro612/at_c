#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(ll s, ll p) {
    for(ll i = 1; i * i <= p; i++) {
        if(p % i == 0 && p / i + i == s) {
            return "Yes";
        }
    }
    return "No";
}

#ifndef _debug
int main() {
    ll s, p;
    cin >> s >> p;
    cout << solve(s, p) << endl;
}
#endif