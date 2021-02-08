#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld solve(ll n, ll k) {
    ll patterns = pow(n, 3);
    if(k == 1 || k == n) {
        return (ld)(1 + ((n - 1) * 3)) / (ld)patterns;
    }

    ll neq = 6 * ((k - 1) * (n - k));
    ll two_eq = 3 * (n - 1);
    return (ld)(1 + neq + two_eq) / (ld)patterns;
}
/*
int main() {
    ll n, k;
    cin >> n >> k;
    cout << fixed << setprecision(12) << solve(n, k) << endl;
}
*/