#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, string s) {
    vector<int> left(10, n), right(10, -1);
    vector<vector<int>> sum(10, vector<int>(30001, 0));
    for(int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        left[digit] = min(i, left[digit]);
        right[digit] = max(i, left[digit]);
        for(int j = 0; j < 10; j++) {
            sum[j][i + 1] = sum[j][i];
        }
        sum[digit][i + 1]++;
    }
    ll res = 0ll;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                if(left[i] != n && right[k] != -1 && left[i] < right[k] &&
                   (sum[j][right[k]] - sum[j][left[i] + 1]) > 0)
                    res++;
            }
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
    return 0;
}
#endif