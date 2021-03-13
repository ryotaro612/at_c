#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n) {
    if(n == 1ll)
        return 1ll;

    ll c = 1;
    while(true) {
        if(((c + 1) * (c + 2)) / 2 < n + 1)
            c++;
        else
            break;
    }
    return n - c + 1;
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
#endif