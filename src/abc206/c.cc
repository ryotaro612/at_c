#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll all = (n * (n - 1ll)) / 2ll;

    map<ll, ll> mp;
    for(auto aa : a) {
        mp[aa]++;
    }
    for(auto p : mp) {
        if(p.second >= 2) {
            all -= (p.second * (p.second - 1ll)) / 2ll;
        }
    }
    cout << all << endl;
    return 0;
}
#endif