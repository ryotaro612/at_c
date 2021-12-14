#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];

    map<ll, int> mp;
    set<ll> a;
    for(int i = 0; i < k; i++) {
        mp[c[i]]++;
        a.insert(c[i]);
    }
    int ans = (int)a.size();
    for(int i = k; i < n; i++) {
        mp[c[i - k]]--;
        if(mp[c[i - k]] == 0ll) {
            a.erase(c[i - k]);
        }
        mp[c[i]]++;
        a.insert(c[i]);
        ans = max(ans, (int)a.size());
    }
    cout << ans << endl;
    return 0;
}
#endif