#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double solve(double sx, double sy, double gx, double gy) {
    double diff = (abs(gx - sx) * sy) / (sy + gy);
    return sx > gx ? sx - diff : sx + diff;
}
/*
int main() {
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    cout << fixed << setprecision(15) << solve(sx, sy, gx, gy);
}
*/