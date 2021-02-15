#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll solve(ll b, ll c) {
    if(b == 0ll) {
        return c;
    }
    if(c == 1) 
        return 2;
    if(b > 0ll) {
        if(c > (b * 2ll)) {
            return c + (b * 2ll - 1ll);
        } else {
            return 2ll * c - 1ll;
        }
    }
    if(c > (-b * 2ll + 1ll)) {
        return c + (-b * 2ll);
    } else {
        return 2ll * c - 1ll;
    }
}
/*
int main() {
    ll b, c;
    cin >> b >> c;
    cout << solve(b, c) << endl;
}
*/