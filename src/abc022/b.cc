#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> count;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    ll res = 0ll;
    for(int i = 0; i < n; i++) {
        if(count.find(a[i]) != count.end()) {
            res++;
        } else {
            count.insert(a[i]);
        }
    }

    cout << res << endl;
    return 0;
}
#endif