#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for(int i = 0; i < n; i++) {
        ll b;
        cin >> b;
        a[i] = {b, i};
    }
    sort(a.begin(), a.end(), greater<pair<ll, int>>());

    cout << a[1].second + 1 << endl;
    return 0;
}
#endif