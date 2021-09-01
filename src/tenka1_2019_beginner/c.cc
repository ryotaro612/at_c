#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, string s) {
    vector<int> white(n, 0), black(n, 0);
    for(int i = 0; i < n; i++) {
        if(s[i] == '#')
            black[i]++;
        if(i != 0)
            black[i] += black[i - 1];
    }
    for(int i = 0; i < n; i++) {
        if(s[n - 1 - i] == '.')
            white[i]++;
        if(i != 0)
            white[i] += white[i - 1];
    }
    int res = n;
    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            res = min(white[n - 1], res);
        } else if(i == n) {
            res = min(black[n - 1], res);
        } else {
            res = min(black[i - 1] + white[n - 1 - i], res);
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << endl;
}
#endif