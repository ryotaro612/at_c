#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, vector<int> &x) {
    if(n >= m)
        return 0;
    vector<int> d(m - 1);
    sort(x.begin(), x.end());
    for(int i = 0; i < m - 1; i++) {
        d[i] = x[i + 1] - x[i];
    }
    sort(d.begin(), d.end());
    int res = 0;
    for(int i = 0; i < m - n; i++) {
        res += d[i];
    }
    return res;
}
#ifndef _debug
int main() {

    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++)
        cin >> x[i];

    cout << solve(n, m, x);
    return 0;
}
#endif
