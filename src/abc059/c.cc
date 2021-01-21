#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a) {
    ll sum = 0, count = 0;
    for(int i = 0; i < n; i++) {
        ll temp = sum + a[i];
        if(i % 2 == 0) {
            if(temp > 0) {
                sum = temp;
                continue;
            } else {
                ll delta = abs(temp) + 1;
                count += delta;
                sum = temp + delta;
            }
        } else { // odd
            if(temp < 0) {
                sum = temp;
                continue;
            } else { // temp > 0
                ll delta = -temp - 1;
                count += abs(delta);
                sum = temp + delta;
            }
        }
    }
    ll res = count;
    sum = count = 0;
    for(int i = 0; i < n; i++) {
        ll temp = sum + a[i];
        if(i % 2 == 1) { // odd
            if(temp > 0) {
                sum = temp;
                continue;
            } else {
                ll delta = abs(temp) + 1;
                count += delta;
                sum = temp + delta;
            }
        } else { // odd
            if(temp < 0) {
                sum = temp;
                continue;
            } else { // temp > 0
                ll delta = -temp - 1;
                count += abs(delta);
                sum = temp + delta;
            }
        }
    }
    res = min(res, count);
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
}
*/