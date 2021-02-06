#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(double x, double y, double r) {
    ll res = 0ll;
    ll top = floor(y + r);
    ll under = ceil(y - r);
    // cout << y + r << "," << y - r << " -> " << top << " " << bottom << " " <<
    // under << endl;

    for(ll i = top; i >= under; i--) {
        double diff = abs(((double)i) - y);
        double width = sqrt(r * r - diff * diff);
        res += floor(x + width) - ceil(x - width) + 1ll;
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