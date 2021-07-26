#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000ll;

ll solve(int n, vector<ll> &a, vector<ll> &b) {

    vector<ll> aa(n), bb(n);

    for(int i = 0; i < n; i++) {
        aa[i] = a[i];
        bb[i] = b[i];
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    if(n % 2ll == 0ll) {
        return (bb[n / 2 - 1] + bb[n / 2]) - (aa[n / 2 - 1] + aa[n / 2]) + 1ll;
    } else {
        int mid = (n - 1) / 2;
        return bb[mid] - aa[mid] + 1ll;
    }
}
#ifndef _LOCAL

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    cout << solve(n, a, b) << endl;
    return 0;
}
#endif