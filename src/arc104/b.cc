#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, string s) {
    vector<int> a(n + 1, 0), t(n + 1, 0), c(n + 1, 0), g(n + 1, 0);
    for(int i = 0; i < n; i++) {
        a[i + 1] = a[i];
        t[i + 1] = t[i];
        c[i + 1] = c[i];
        g[i + 1] = g[i];
        if(s[i] == 'A') {
            a[i + 1]++;
        } else if(s[i] == 'T') {
            t[i + 1]++;
        } else if(s[i] == 'C') {
            c[i + 1]++;
        } else if(s[i] == 'G') {
            g[i + 1]++;
        }
    }
    /*
    for(auto aa : a) {
        cout << aa << " ";
    }
    cout << endl;
    */
    ll res = 0ll;
    for(int i = 2; i <= n; i += 2) {
        for(int j = 0; j + i <= n; j++) {
            if(a[j + i] - a[j] == t[j + i] - t[j] &&
               c[j + i] - c[j] == g[j + i] - g[j])
                res++;
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
}
#endif