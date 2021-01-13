#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int m, vector<int> l, vector<int> r, vector<int> s) {

    vector<int> mv(m, 0);
    for(int i = 0; i < n; i++) {
        mv[l[i] - 1] += s[i];
        mv[r[i]] -= s[i];
    }
    for(int i = 1; i < m; i++) {
        mv[i] += mv[i - 1];
    }
    int least = 2147483647;
    for(auto mm : mv) {
        least = min(least, mm);
    }

    ll res = 0;
    for(auto ss : s) {
        res += ss;
    }
    return res - least;
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n), s(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> s[i];
    }

    cout << solve(n, m, l, r, s) << endl;
    return 0;
}
*/