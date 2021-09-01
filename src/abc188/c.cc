#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll pow2(int n) {
    if(n == 0)
        return 1;
    return pow2(n - 1) * 2ll;
}

ll dfs(int n, vector<pair<int, ll>> a) {
    if(n == 1)
        return a[0].second > a[1].second ? a[1].first : a[0].first;
    vector<pair<int, ll>> aa;
    for(int i = 0; i < (int)a.size() - 1; i += 2)
        aa.push_back(a[i].second < a[i + 1].second ? a[i + 1] : a[i]);
    return dfs(n - 1, aa);
}

ll solve(int n, vector<ll> a) {
    vector<pair<int, ll>> aa(pow2(n));
    for(int i = 0; i < pow2(n); i++)
        aa[i] = make_pair(i + 1, a[i]);
    return dfs(n, aa);
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(pow2(n));
    for(int i = 0; i < pow2(n); i++)
        cin >> a[i];
    cout << solve(n, a);
}
#endif