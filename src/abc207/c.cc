#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<ll> t, l, r;

bool inter(int a, int b) {
    ld l_a, r_a, l_b, r_b;
    if(t[a] == 1ll || t[a] == 2ll) {
        l_a = (ld)l[a];
    } else {
        l_a = (ld)l[a] + 0.1;
    }
    if(t[a] == 1ll || t[a] == 3ll) {
        r_a = (ld)r[a];
    } else {
        r_a = (ld)r[a] - 0.1;
    }
    if(t[b] == 1ll || t[b] == 2ll) {
        l_b = (ld)l[b];
    } else {
        l_b = (ld)l[b] + 0.1;
    }
    if(t[b] == 1ll || t[b] == 3ll) {
        r_b = (ld)r[b];
    } else {
        r_b = (ld)r[b] - (ld)0.1;
    }
    /*
if(a == 1 && b == 2) {
    cout << l_a << " " << r_a << " " << l_b << " " << r_b << endl;
}
    */

    if(r_a < l_b || r_b < l_a)
        return false;
    return true;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    t.resize(n);
    l.resize(n);
    r.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> l[i] >> r[i];
    }
    ll ans = 0ll;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(inter(i, j)) {
                // cout << i + 1 << " " << j + 1 << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
#endif