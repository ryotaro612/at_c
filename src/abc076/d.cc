#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double solve(int n, vector<double> t, vector<double> v) {
    for(int i = 1; i < n; i++) {
        t[i] += t[i - 1];
    }
    double x = 0;
    vector<double> a;
    for(int i = 0; i <= t[n - 1] * 2; i++) {
        double temp = i == 0 ? 0 : x;
        temp = min(i == t[n - 1] * 2 ? 0 : t[n - 1] - x, temp);
        for(int j = 0; j < n; j++) {
            if(j == 0) {
                if(x <= t[j]) {
                    temp = min(temp, v[j]);
                } else {
                    temp = min(temp, v[j] + x - t[j]);
                }
            } else {
                if(x < t[j - 1]) {
                    temp = min(temp, v[j] + t[j - 1] - x);
                } else if(t[j - 1] <= x && x <= t[j]) {
                    temp = min(temp, v[j]);
                } else {
                    temp = min(temp, v[j] + x - t[j]);
                }
            }
        }
        a.push_back(temp);
        x += 0.5;
    }
    double res = 0;
    for(int i = 1; i < (int)a.size(); i++) {
        res += (a[i - 1] + a[i]) * 0.25;
    }
    return res;
}
/*
int main() {
    ll n;
    cin >> n;
    vector<double> t(n), v(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << fixed << setprecision(15) << solve(n, t, v);
}
*/