#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(double x, double y, double r) {
    ll res = 0ll;

    ll top = floor(y + r);
    ll bottom = ceil(y);
    ll under = ceil(y - r);
    cout << y + r << "," << y - r << " -> " << top << " " << bottom << " "
         << under << endl;

    for(ll i = top; i >= bottom; i--) {
        double width = sqrt(r * r - abs(i - y) * abs(i - y));
        res += floor(x + width) - ceil(x - width) + 1;
    }
    for(ll i = under; bottom > i; i++) {
        double width = sqrt(r * r - abs(i - y) * abs(i - y));
        res += floor(x + width) - ceil(x - width) + 1;
    }

    return res;
}
/*
int main() {
    double x, y, r;
    cin >> x >> y >> r;
    cout << solve(x, y, r) << endl;
}
*/