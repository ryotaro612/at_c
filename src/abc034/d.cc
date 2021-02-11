#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int n, int k, vector<ll> w, vector<int> p, double threashold) {
    vector<double> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = (double)w[i] * ((double)p[i] - 100 * threashold);
    }
    sort(v.begin(), v.end(), greater<double>());
    double res = 0;
    for(int i = 0; i < k; i++) {
        res += v[i];
    }
    return res > 0;
}

double solve(int n, int k, vector<ll> w, vector<int> p) {
    double lb = 0.0, ub = 1.01;
    for(int i = 0; i < 100; i++) {
        double mid = (lb + ub) / (double)2;
        if(check(n, k, w, p, mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    return ub*100;
}
/*
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> w(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> p[i];
    }
    cout << fixed << setprecision(12) << solve(n, k, w, p) << endl;
}
*/