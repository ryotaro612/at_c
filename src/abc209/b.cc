#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll acc = 0ll;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 1)
            acc += a[i] - 1;
        else
            acc += a[i];
    }
    if(acc <= x)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}
#endif