#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll money = 1000ll, stock = 0ll;
    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            // TODO
            money += stock * a[i];
            stock = 0ll;
            continue;
        }
        // == ?
        if(a[i] < a[i + 1]) {
            stock += (money / a[i]);
            money -= (money / a[i]) * a[i];
        } else if(a[i] > a[i + 1]) {
            money += a[i] * stock;
            stock = 0ll;
        }
    }
    cout << money << endl;
    return 0;
}
#endif