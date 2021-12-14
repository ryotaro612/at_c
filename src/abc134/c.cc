#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> b(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    vector<ll> ans(n, b[0]);
    /*
    for(int i = 0; i < n; i++)
        cout << a[i] << endl;
    cout << " ---- " << endl;
    for(int i = 0; i < n; i++)
        cout << b[i] << endl;
    cout << " ---- " << endl;
    */
    if(b[0] != b[1]) {
        for(int i = 0; i < n; i++) {
            if(a[i] == b[0])
                ans[i] = b[1];
        }
    }

    for(auto e : ans)
        cout << e << endl;
    return 0;
}
#endif