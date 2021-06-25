#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MX = 1000000000ll;

#ifndef _LOCAL
int main() {
    ll n, k, s;
    cin >> n >> k >> s;

    ll other = MX;
    while(other == s)
        other--;

    vector<ll> a(n, other);
    for(int i = 0; i < k; i++) {
        a[i] = s;
    }

    for(int i = 0; i < n; i++) {
        cout << a[i];
        if(i < n - 1)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}
#endif