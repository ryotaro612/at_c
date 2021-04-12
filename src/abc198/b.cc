#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(ll n) {
    if(n == 0)
        return "Yes";

    while(n % 10ll == 0ll)
        n /= 10ll;

    string s = to_string(n);
    bool ok = true;
    int size = (int)s.size();
    for(int i = 0; i < size / 2; i++) {
        if(s[i] != s[size - 1 - i]) {
            ok = false;
            break;
        }
    }
    return ok ? "Yes" : "No";
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif