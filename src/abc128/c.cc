#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int n, int m, vector<int> k, vector<vector<int>> s, vector<int> p) {
    int res = 0;
    for(int i = 0; i < (1 << n); i++) {
        bool ok = true;
        for(int j = 0; j < m; j++) {
            int count = 0;
            for(int l = 0; l < k[j]; l++) {
                if(i & (1 << (s[j][l] - 1))) {
                    count++;
                }
            }
            if(count % 2 != p[j]) {
                ok = false;
                break;
            }
        }
        if(ok)
            res++;
    }
    return res;
}
#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(m), p(m);
    vector<vector<int>> s(10, vector<int>(10));
    for(int i = 0; i < m; i++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> p[i];
    }
    cout << solve(n, m, k, s, p) << endl;
    return 0;
}
#endif