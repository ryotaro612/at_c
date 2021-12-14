#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef long double ld;

ld solve(int n, ld d, ld h, vector<ld> dv, vector<ld> hv) {
    ld ub = 1001, lb = -1;

    for(int i = 0; i < 1000; i++) {
        ld mid = (ub + lb) / (ld)2;
        // cout << mid << endl;
        bool ok = true;
        // cout << h << " ====" << d << endl;
        for(int j = 0; j < n; j++) {
            ld y = ((h - mid) / d) * dv[j] + mid;
            if(y < hv[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            // cout << "ok " << endl;
            ub = mid;
        } else {
            // cout << "no " << endl;
            lb = mid;
        }
    }
    return min(max(ub, (ld)0), (ld)1000);
    // return ub;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    ld d, h;
    cin >> n >> d >> h;
    vector<ld> dv(n), hv(n);
    for(int i = 0; i < n; i++)
        cin >> dv[i] >> hv[i];
    ld ans = solve(n, d, h, dv, hv);
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
#endif