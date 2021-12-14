#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    set<ll> r, c;
    for(int i = 0; i < n; i++) {
        r.insert(a[i]);
        c.insert(b[i]);
    }
    map<ll, ll> mp_a, mp_b;
    int i = 1;
    for(auto aa : r) {
        mp_a[aa] = i++;
    }
    i = 1;
    for(auto aa : c) {
        mp_b[aa] = i++;
    }
    for(int i = 0; i < n; i++) {
        cout << mp_a[a[i]] << " " << mp_b[b[i]] << endl;
    }

    return 0;
}
#endif