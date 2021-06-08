#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < d; j++)
            cin >> x[i][j];
    }
    vector<ll> dists;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ll temp = 0ll;
            for(int k = 0; k < d; k++) {
                temp += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            dists.push_back(temp);
        }
    }
    map<ll, bool> mp;
    for(ll i = 1; i <= 400ll; i++) {
        mp[i * i] = true;
    }
    int ans = 0;
    for(auto d : dists) {
        if(mp[d])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
#endif