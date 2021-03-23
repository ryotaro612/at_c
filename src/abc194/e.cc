#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int n, int m, vector<int> a) {
    vector<ll> sum(n, 0);
    vector<int> mex(n - m + 1);
    for(int i = 0; i < m; i++) {
        sum[a[i]]++;
    }
    int mv = 0;
    while(sum[mv] > 0) {
        mv++;
    }
    mex[0] = mv;
#ifdef _LOCAL
    cout << "initial mex: " << mex[0] << endl;
#endif
    for(int i = m; i < n; i++) {
        sum[a[i]]++;
        sum[a[i - m]]--;
        if(a[i - m] == 0 && a[i - m] < mv)
            mv = a[i - m];

        while(sum[mv] > 0) {
            mv++;
        }
        mex[i - m + 1] = mv;
    }

    int res = n;
    for(auto m : mex) {
        res = min(res, m);
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, m, a) << endl;
    return 0;
}
#endif