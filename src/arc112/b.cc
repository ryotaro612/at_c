#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll b, ll c) {
    if(b > 0) {
        if(c>=b*2ll) {
            return c + (b * 2ll - 1);
        } else {
            return 2ll* c - 1ll;
        }
    }
    if(b == 0) {
        return c;
    }
    return c + min(c - 1ll, -b * 2ll);
}
/*
int main() {
    ll b, c;
    cin >> b >> c;
    cout << solve(b, c) << endl;
}
*/