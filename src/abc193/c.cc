#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n) {
    set<ll> found;
    for(ll i = 2; i <= 100000; i++) {
        int count = 2;
        while(true) {
            ll test =  pow(i, count);
            if(test > n)
                break;
            found.insert(test);
            count++;
        }
    }
    return n - (ll)found.size();
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif