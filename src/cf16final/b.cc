#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;

    ll k = 1;
    for(;;) {
        if((k + 1ll) * (k + 2ll) / 2ll <= n)
            k++;
        else
            break;
    }
    ll gap = (k + 1ll) * (k + 2ll) / 2ll - n;

    if(gap == 0) {
        for(int i = 1; i <= k; i++) {
            cout << i << endl;
        }
        return 0;
    } else {
        for(int i = 1; i <= k + 1; i++) {
            if(gap != i)
                cout << i << endl;
        }
    }
    return 0;
}
#endif