#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> m;
    for(int i = 0; i < n; i++)
        m[a[i]]++;

    vector<pair<int, int>> v;
    for(auto p : m) {
        v.push_back(make_pair(p.second, p.first));
    }
    int siz = v.size();
    sort(v.begin(), v.end());
    ll res = 0ll;
    for(int i = 0; i < siz - k; i++) {
        res += v[i].first;
    }
    cout << res << endl;
    return 0;
}
#endif