#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll c_a = 0ll, c_b = 0ll;
    for(int i = 0; i < n; i++) {
        if(a[i] < b[i]) {
            c_a += (b[i] - a[i]) / 2ll;
        } else if(a[i] > b[i]) {
            c_b += a[i] - b[i];
        }
    }
    if(c_a >= c_b) {
        cout << "Yes" << endl;
    } else
        cout << "No" << endl;
    return 0;
}
#endif