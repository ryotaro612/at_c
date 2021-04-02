#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, vector<ll> a) {
    map<ll, set<int>> m;
    for(int i = 0; i < n; i++) {
        m[i + 1 - a[i]].insert(i);
    }
    ll res = 0ll;
    for(int i = 0; i < n - 1; i++) {
        set<int> index = m[a[i] + i + 1];
        auto it = upper_bound(index.begin(), index.end(), i);
        int count = distance(it, index.end());
        res += count;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif