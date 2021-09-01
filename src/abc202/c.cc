#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];

    // Aと同じ値のBのインデックスの集合が要素
    vector<vector<ll>> ma(n, vector<ll>());
    for(int i = 0; i < n; i++) {
        ma[b[i] - 1].push_back(i);
    }
    vector<ll> mc(n, 0ll);
    for(int i = 0; i < n; i++) {
        mc[c[i] - 1]++;
    }
    ll ans = 0ll;
    vector<ll> cache(n, -1);
    for(int i = 0; i < n; i++) {
        if(cache[a[i] - 1] != -1) {
            ans += cache[a[i] - 1];
            continue;
        }
        ll temp = 0ll;
        vector<ll> index_of_b_same_val_as_a = ma[a[i] - 1];
        for(auto b_index_b_val_is_same_as_a_val : index_of_b_same_val_as_a) {
            temp += mc[b_index_b_val_is_same_as_a_val];
        }
        cache[a[i] - 1] = temp;
        ans += temp;
    }
    cout << ans << endl;
}
#endif