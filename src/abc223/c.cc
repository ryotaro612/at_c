#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

double calc_length(vector<int> &a, vector<int> &b, double time) {
    double elapsed = 0, res = 0;
    rep(i, a.size()) {
        if(elapsed + (double)a[i] / (double)b[i] < time) {
            elapsed += (double)a[i] / (double)b[i];
            res += a[i];
        } else {
            res += (time - elapsed) * b[i];
            break;
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<int> r_a(a.begin(), a.end()), r_b(b.begin(), b.end());
    reverse(r_a.begin(), r_a.end());
    reverse(r_b.begin(), r_b.end());

    double lb = 0ll, ub = 1000000000ll;
    double sum = 0;
    rep(i, n) sum += (double)a[i];
    // cout << sum << endl;
    rep(i, 1000) {
        double mid = (lb + ub) / 2.0;
        double length = calc_length(a, b, mid) + calc_length(r_a, r_b, mid);
        // cout << mid << " " << length << endl;
        if(sum <= length)
            ub = mid;
        else
            lb = mid;
    }
    cout << fixed << setprecision(12) << calc_length(a, b, lb) << endl;
    return 0;
}
#endif