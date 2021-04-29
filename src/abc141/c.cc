#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL {
int main() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(q);
    for(int i = 0; i < q; i++)
        cin >> a[i];

    vector<ll> count(n, 0ll);
    for(auto aa : a)
        count[aa - 1]++;
    for(int i = 0; i < n; i++) {
        if(k - (q - count[i]) > 0)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
#endif