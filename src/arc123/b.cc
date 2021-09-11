#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<ll> second;
    for(int i = 0, j = 0; i < n; i++) {
        while(j < n) {
            if(a[i] < b[j]) {
                second.push_back(b[j]);
                j++;
                break;
            } else { // a[i] >= b[j]
                j++;
            }
        }
    }
    vector<ll> third;
    for(int i = 0, j = 0; i < (int)second.size(); i++) {
        while(j < n) {
            if(second[i] < c[j]) {
                third.push_back(c[j]);
                j++;
                break;
            } else { // a[i] >= b[j]
                j++;
            }
        }
    }
    return third.size();
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    cout << solve(n, a, b, c) << endl;

    return 0;
}
#endif