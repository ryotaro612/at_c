#include <bits/stdc++.h>
typedef long double ld;
using namespace std;

const long double PI = acos(-1);

void out(ld v) { cout << fixed << setprecision(12) << v << endl; }

ld calc(ld a, ld b, ld c, ld theta) {
    ld t = theta / (c * PI);
    return a * t + b * sin(theta);
}

ld search(ld a, ld b, ld c, ld lb, ld ub) {
    for(int i = 0; i < 10000; i++) {
        ld mid = (lb + ub) / (ld)2;
        if(calc(a, b, c, mid) > (ld)100)
            ub = mid;
        else
            lb = mid;
    }
    return ub / (c * PI);
}

void solve() {
    ld a, b, c;
    cin >> a >> b >> c;

    out(search(a, b, c, 0, 3000 * c * PI));

}

#ifdef ONLINE_JUDGE
int main() {
    solve();
    return 0;
}
#endif
