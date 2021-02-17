#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

double solve(int n, int k, vector<int> r) {
    sort(r.begin(), r.end(), greater<int>());
    double res = 0;
    for(int i = k - 1; i >= 0; i--) {
        res = (res + r[i]) / 2;
    }
    return res;
}
/*
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    for(int i = 0; i < n; i++) {
        cin >> r[i];
    }
    cout << fixed << setprecision(12) << solve(n, k, r) << endl;
}
*/