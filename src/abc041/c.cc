#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for(int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        a[i] = make_pair(temp, i + 1);
    }
    sort(a.begin(), a.end(), greater<pair<ll, int>>());

    for(int i = 0; i < n; i++) {
        cout << a[i].second << endl;
    }

    return 0;
}
#endif