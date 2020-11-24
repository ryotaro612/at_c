#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll r1, ll c1, ll r2, ll c2) {
    ll x = abs(r1 - r2);
    ll y = abs(c2 - c1);
    if(x == 0 && y == 0)
        return 0;
    if(x == y || x + y <= 3)
        return 1;
    if((x + y) % 2 == 0)
        return 2;
    if(abs(x - y) <= 3 || x + y <= 6)
        return 2;
    return 3;
}
/*
int main() {
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << solve(r1, c1, r2, c2);
}
*/