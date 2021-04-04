#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> solve(int n, int m, vector<int> a) {
    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++)
        b[n - 1 - i] = make_pair(i, n - 1 - i);
    for(int i = 0, clock = n; i < m; i++, clock++) {
        b[a[i] - 1] = make_pair(clock, a[i] - 1);
    }

    sort(b.begin(), b.end(), greater<pair<int, int>>());
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        res[i] = b[i].second + 1;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    vector<int> res = solve(n, m, a);
    for(auto r : res)
        cout << r << endl;
}
#endif