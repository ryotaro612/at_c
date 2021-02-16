#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a, ll b, ll x) {
    ll res_b = b / x + 1;
    if(a == 0) {
        return res_b;
    }
    ll res_a = (a - 1) / x + 1;

    return res_b - res_a;
}
/*
int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    cout << solve(a, b, x) << endl;
    return 0;
}
*/